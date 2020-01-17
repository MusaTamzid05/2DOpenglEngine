#ifndef MATERIAL_H
#define MATERIAL_H

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Shape {

    struct Material {


        Material(float shininess = 10.0f,
                const glm::vec3& ambient = glm::vec3(0.5 , 0.5 , 0.5),
                const glm::vec3& diffuse = glm::vec3(0.5 , 0.5 , 0.5),
                const glm::vec3& specular = glm::vec3(0.5 , 0.5 , 0.5)
                ):
            shininess(shininess),
            ambient(ambient),
            diffuse(diffuse),
            specular(specular) {

            }


        float shininess;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

    };
}

#endif
