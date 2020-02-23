#ifndef ROTATE_H
#define ROTATE_H

#include <iostream>
#include <glm/glm.hpp>
namespace Shape {

    struct Rotate {
        Rotate(float angle , const  glm::vec3& vec);
        float angle;
        glm::vec3 vec;
    };

    std::ostream& operator<<(std::ostream& out , const Rotate& rotate);
};


#endif
