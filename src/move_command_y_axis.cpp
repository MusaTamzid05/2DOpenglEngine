#include "move_command_y_axis.h"

namespace OpenGL {

    MoveCommandYAxis::MoveCommandYAxis(float increament_value):
    increament_value(increament_value){

    }


    MoveCommandYAxis::~MoveCommandYAxis() {
    }


    void MoveCommandYAxis::execute(Shape::Shape* shape) {

        glm::vec3 pos = shape->get_pos3D();
        pos.y += increament_value;
        shape->set_pos(pos);
    }

    void MoveCommandYAxis::undo(Shape::Shape* shape) {

    }
};
