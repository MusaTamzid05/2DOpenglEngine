#include "texture_holder.h"
#include "shader.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

namespace  OpenGL {

    TextureHolder::TextureHolder(const std::string& file_path , Shader* shader):
    m_shader(shader){
        stbi_set_flip_vertically_on_load(true);
        init();
        load_image_opengl(file_path);



    }

    void TextureHolder::init() {

        glGenTextures(1 , &id);
        glBindTexture(GL_TEXTURE_2D , id);

        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T, GL_REPEAT);


        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);
    }

    void TextureHolder::load_image_opengl(const std::string& file_path) {

        unsigned char* data = stbi_load(
                file_path.c_str(),
                &width,
                &height,
                &nr_channels,
                0);

        if(data == nullptr) {
            std::cerr << "Could not load image " << file_path << "\n";
            return;
        }

        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGB,
                width,
                height,
                0,
                GL_RGB,
                GL_UNSIGNED_BYTE,
                data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);


        m_shader->use();
        m_shader->setInt("texture" , id);
    }

    void TextureHolder::bind() {

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D , id);
    }
};
