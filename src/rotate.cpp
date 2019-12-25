#include "rotate.h"

namespace Shape {

    std::ostream& operator<<(std::ostream& out , const Rotate& rotate) {
        out << "Rotate : " <<  rotate.angle;
        return out;
    }
};
