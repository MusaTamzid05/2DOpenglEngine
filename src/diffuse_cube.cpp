#include "diffuse_cube.h"



namespace Shape {

    DiffuseCube::DiffuseCube(
            Shape* src,
            const Color& color):
            LightCube(
                    "../shaders/light_cube.vs" ,
                    "../shaders/light_cube_diffuse.fs",
                    src,
                    color){

    }


    void DiffuseCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

        m_shader->use();
        Color light_color = src->get_color();
        glm::vec3 light_pos = src->get_pos3D();


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

    void DiffuseCube::update() {

    }

};
