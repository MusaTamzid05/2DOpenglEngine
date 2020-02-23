#include "rotate.h"
#include "util.h"

namespace Shape {

    Rotate::Rotate(float angle , const glm::vec3& vec):
        angle(angle),
        vec(vec) {

        }

    std::ostream& operator<<(std::ostream& out , const Rotate& rotate) {
        out << "Rotate => angle :  " <<  rotate.angle << " , ( " << rotate.vec.x << "," << rotate.vec.y << "," << rotate.vec.z << ")";
        return out;
    }
};
