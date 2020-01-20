#include "material_cube.h"
#include "camera.h"
#include "util.h"


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
            material(),
            light_property(){

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
    }


    void MaterialCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

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

        Shape::draw(projection , view);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 36);
    }

    void MaterialCube::update() {

    }

};
