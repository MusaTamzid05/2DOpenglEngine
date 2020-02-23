#include "direction_light_cube.h"
#include "texture_light_cube.h"
#include "texture_holder.h"
#include "camera.h"
#include "util.h"

namespace Shape {

    DirectionLightCube::DirectionLightCube(
            Shape* src ,
            OpenGL::Camera* camera,
            const std::string& vertex_shader_path,
            const std::string& fragment_shader_path,
            OpenGL::TextureManager* texture_manager,
            std::vector<std::string> texture_names
            ):TextureLightCube(
                src,
                camera,
                vertex_shader_path,
                fragment_shader_path,
                texture_manager,
                texture_names
                ) {

                m_shader->use();
                m_shader->setVec3("light.direction" ,camera->Position);
            }

    void DirectionLightCube::draw(const glm::mat4& projection , const  glm::mat4 view) {

        m_shader->use();
        glm::vec3 light_pos = src->get_pos3D();
        m_shader->setVec3("viewPos" , m_camera->Position);


        // cannot be serious !!! position
        //  are r , g , b value !!!!


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
};
