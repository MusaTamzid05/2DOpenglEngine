#include "move_command_x_axis.h"

namespace OpenGL {

    MoveCommandXAxis::MoveCommandXAxis(float increament_value):
    increament_value(increament_value){

    }


    MoveCommandXAxis::~MoveCommandXAxis() {
    }


    void MoveCommandXAxis::execute(Shape::Shape* shape) {

        glm::vec3 pos = shape->get_pos3D();
        pos.x += increament_value;
        shape->set_pos(pos);
    }

    void MoveCommandXAxis::undo(Shape::Shape* shape) {

    }
};
