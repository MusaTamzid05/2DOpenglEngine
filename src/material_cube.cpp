#include "material_cube.h"
#include "camera.h"


namespace Shape {

    MaterialCube::MaterialCube(
            Shape* src,
            OpenGL::Camera* camera,
            const Color& color):
            LightCube(
                    "../shaders/light_cube.vs" ,
                    "../shaders/material_cube.fs",
                    src,
                    color),
            m_camera(camera),
            material(){

    }


    void MaterialCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

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

        Shape::draw(projection , view);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 36);
    }

    void MaterialCube::update() {

    }

};
