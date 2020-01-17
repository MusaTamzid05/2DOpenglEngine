#ifndef LIGHT_PROPERTY_H
#define LIGHT_PROPERTY_H

#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Shape {

    struct LightProperty {


        LightProperty(
                const glm::vec3& position = glm::vec3(0.0 , 0.0 , 0.0),
                const glm::vec3& ambient = glm::vec3(0.5 , 0.5 , 0.5),
                const glm::vec3& diffuse = glm::vec3(0.5 , 0.5 , 0.5),
                const glm::vec3& specular = glm::vec3(0.5 , 0.5 , 0.5)
                ):
            position(position),
            ambient(ambient),
            diffuse(diffuse),
            specular(specular) {

            }

        glm::vec3 position;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

    };


    std::ostream& operator<<(std::ostream& out , const LightProperty& light_property);
};

#endif
