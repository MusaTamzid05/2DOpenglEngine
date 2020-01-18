#include "move_command_z_axis.h"

namespace OpenGL {

    MoveCommandZAxis::MoveCommandZAxis(float increament_value):
    increament_value(increament_value){

    }


    MoveCommandZAxis::~MoveCommandZAxis() {
    }


    void MoveCommandZAxis::execute(Shape::Shape* shape) {

        glm::vec3 pos = shape->get_pos3D();
        pos.z += increament_value;
        shape->set_pos(pos);
    }

    void MoveCommandZAxis::undo(Shape::Shape* shape) {

    }
};
