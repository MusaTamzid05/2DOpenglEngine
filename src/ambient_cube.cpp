#include "ambient_cube.h"
#include <iostream>

namespace Shape {

    AmbientCube::AmbientCube(
            Shape* src,
            const Color& color,
            float ambient_strength):
            LightCube(
                    "../shaders/light_cube.vs" ,
                    "../shaders/light_cube_ambient.fs",
                    src,
                    color),
        ambient_strength(ambient_strength)
    {

        m_shader->use();
        m_shader->setFloat("ambientStrength" , ambient_strength);
    }


    void AmbientCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

        m_shader->use();
        Color light_color = src->get_color();

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

    void AmbientCube::update() {

    }

};
