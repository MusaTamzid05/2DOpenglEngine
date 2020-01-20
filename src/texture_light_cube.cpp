#include "texture_light_cube.h"
#include "texture_holder.h"
#include "camera.h"


namespace Shape {

    TextureLightCube::TextureLightCube(
            Shape* src,
            OpenGL::Camera* camera,
            const std::string& texture_path
            ):
            LightCube(src),
            m_camera(camera),
            material(),
            light_property(){
        float vertices[] = {
                        // positions          // normals           // texture coords
                        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
                         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

                        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
                         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

                        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
                        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
                        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
                        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

                         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
                         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
                         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
                         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
                         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
                         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

                        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
                         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
                         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
                         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

                        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
                         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
                         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
                    };
        
        init(vertices ,
                sizeof(vertices) ,
                "../shaders/texture_light_cube.vs" ,
                "../shaders/texture_light_cube.fs"
                );
        Color src_color = src->get_color();
        glm::vec3 light_color(src_color.r , src_color.g , src_color.b);

        glm::vec3 diffuseColor = light_color * glm::vec3(0.5);
        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2);


        light_property.ambient = ambientColor;
        light_property.diffuse = diffuseColor;


        light_property.specular = glm::vec3(
                1.0,
                1.0,
                1.0
                );

        m_texture_holder = new OpenGL::TextureHolder(texture_path , m_shader);

    }

    TextureLightCube::~TextureLightCube() {

    }

    void TextureLightCube::init_mesh(float* vertices , int sizeof_vertices) {

            glGenVertexArrays(1 , &VAO);
            glGenBuffers(1 , &VBO);

            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER , VBO);
            glBufferData(
                    GL_ARRAY_BUFFER ,
                     sizeof_vertices,
                     vertices,
                     GL_STATIC_DRAW);

            glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 8 * sizeof(float),(void*)0);
            glEnableVertexAttribArray(0);


            glVertexAttribPointer(1 , 3 , GL_FLOAT , GL_FALSE , 8 * sizeof(float),(void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);


            glVertexAttribPointer(2 , 2 , GL_FLOAT , GL_FALSE , 8 * sizeof(float),(void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);

            glBindBuffer(GL_ARRAY_BUFFER , 0);
            glBindVertexArray(0);


    }


    void TextureLightCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

        m_shader->use();
        glm::vec3 light_pos = src->get_pos3D();
        m_shader->setVec3("viewPos" , m_camera->Position);


        // cannot be serious !!! position
        //  are r , g , b value !!!!


        m_shader->setVec3("light.position" ,
                light_pos.r,
                light_pos.g,
                light_pos.b
                );

        m_shader->setVec3(
                "material.ambient",
                material.ambient
                );

        m_shader->setVec3(
                "material.diffuse",
                material.diffuse
                );

        m_shader->setVec3(
                "material.specular",
                material.diffuse
                );

        m_shader->setFloat(
                "material.shininess",
                material.shininess
                );

        m_shader->setVec3(
                "light.ambient",
                light_property.ambient
                );

        m_shader->setVec3(
                "light.diffuse",
                light_property.diffuse
                );

        m_shader->setVec3(
                "light.specular",
                light_property.specular
                );

        m_texture_holder->bind();
        Shape::draw(projection , view);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 36);
    }


    void TextureLightCube::update() {

    }

};
