#include "texture_light_cube.h"
#include "texture_holder.h"
#include "camera.h"
#include "util.h"


namespace Shape {

    TextureLightCube::TextureLightCube(
            Shape* src,
            OpenGL::Camera* camera,
            OpenGL::TextureManager* texture_manager,
            const std::string& texture_name 
            ):
            LightCube(src),
            m_camera(camera),
            material(),
            light_property()
    {
        std::vector<std::string> texture_names;
        texture_names.push_back(texture_name);
        init_data(texture_manager , texture_names);
    }


    TextureLightCube::TextureLightCube(Shape* src ,
            OpenGL::Camera* camera,
            OpenGL::TextureManager* texture_manager,
            std::vector<std::string> texture_names):
            LightCube(src),
            m_camera(camera),
            material(),
            light_property() {
                init_data(texture_manager , texture_names);
    }

    TextureLightCube::~TextureLightCube() {

    }

    void TextureLightCube::init_data(OpenGL::TextureManager* texture_manager, std::vector<std::string> texture_names) {

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
        format_src_color(src_color);

        glm::vec3 light_color(src_color.r , src_color.g , src_color.b);

        glm::vec3 diffuseColor = light_color * glm::vec3(0.8);
        glm::vec3 ambientColor = light_color;

        Util::print_vec3(ambientColor);
        Util::print_vec3(diffuseColor);


        light_property.ambient = ambientColor;
        light_property.diffuse = diffuseColor;


        light_property.specular = glm::vec3(
                1.0,
                1.0,
                1.0
                );

        for(std::string texture_name : texture_names) {
            OpenGL::TextureData* texture_data = texture_manager->get(texture_name);

            if(texture_data == nullptr) {
                std::cerr << "Texture " << texture_name << " not loaded for texture_cube.\n";
                continue;
            }

            texture_data_list.push_back(texture_data);
            
        }
    }

    void TextureLightCube::format_src_color(Color& src_color) {

        // if one color value is to higher than others,
        // that it causes serious issue when in texture
        // so here we make all values of the color
        // closer to each other.
        // here we we the highest value just
        // higher than others
        // TODO: very hacky code!!

        std::vector<float> color_values;
        color_values.push_back(src_color.r);
        color_values.push_back(src_color.g);
        color_values.push_back(src_color.b);

        float max_value = -1000.0f;

        for(unsigned int i = 0 ; i < color_values.size() ; i++) {
            if(color_values[i] > max_value) {
                max_value = color_values[i];
                continue;
            }
        }

        if(src_color.r == max_value) {
            src_color.r = max_value + 0.2;
        } else {
            src_color.r = max_value;
        }

        if(src_color.g == max_value) {
            src_color.g = max_value + 0.2;
        } else {
            src_color.g = max_value;
        }


        if(src_color.b == max_value) {
            src_color.b = max_value + 0.2;
        } else {
            src_color.b = max_value;
        }

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

        m_shader->setInt(
                "material.diffuse",
                0
                );

        m_shader->setInt(
                "material.specular",
                1
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

        Shape::draw(projection , view);

        for(unsigned int i = 0 ; i < texture_data_list.size() ; i++)
            texture_data_list[i]->bind(i);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 36);
    }


    void TextureLightCube::update() {

    }

};
