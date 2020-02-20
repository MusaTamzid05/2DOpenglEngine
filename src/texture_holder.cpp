#include "texture_holder.h"
#include "shader.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

namespace  OpenGL {

    TextureHolder::TextureHolder(const std::string& path , Shader* shader):
      m_shader(shader){

        m_shader->use();
        glGenTextures(1 , &id);
        
        unsigned char* data = stbi_load(path.c_str(),
                &width ,
                &height,
                &nr_components,
                0);

        if(!data) {
            std::cerr << "Could not load " << path << "\n";
            return;
        }

        std::cout <<  "texture : " << path << " loaded sucessfully.\n";
        unsigned int format;

        if (nr_components == 1)
            format = GL_RED;
        else if (nr_components == 3)
            format = GL_RGB;
        else if (nr_components == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D , id);
        glTexImage2D(GL_TEXTURE_2D , 0 , format , width , height , 0 , format , GL_UNSIGNED_BYTE , data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);

        stbi_image_free(data);
    }

    void TextureHolder::bind() {

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TRIANGLES , id);
    }
};
