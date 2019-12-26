#include "specular_cube.h"
#include "camera.h"

namespace Shape {

    SpecularCube::SpecularCube(
            Shape* src,
            OpenGL::Camera* camera,
            float specular_strength,
            const Color& color):
            LightCube(
                    "../shaders/light_cube.vs" ,
                    "../shaders/light_cube_specular.fs",
                    src,
                    color),
            m_camera(camera),
            specular_strength(specular_strength){

                m_shader->use();
                m_shader->setFloat("specularStrength" , specular_strength);

    }


    void SpecularCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

        m_shader->use();
        Color light_color = src->get_color();
        glm::vec3 light_pos = src->get_pos3D();

        m_shader->setVec3("viewPos" , m_camera->Position);

        m_shader->setVec3("lightPos" ,
                light_pos.r,
                light_pos.g,
                light_pos.b
                );
        m_shader->setVec3("lightColor" ,
                light_color.r,
                light_color.g,
                light_color.b
                );

        m_shader->setVec3("objectColor" ,
                m_color.r,
                m_color.g,
                m_color.b
                );

        Shape::draw(projection , view);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 36);
    }

    void SpecularCube::update() {

    }

};
