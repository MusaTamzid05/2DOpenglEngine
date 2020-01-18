#ifndef MOVE_COMMAND_Y_AXIS_H
#define MOVE_COMMAND_Y_AXIS_H

#include "command.h"

namespace OpenGL {

    class MoveCommandYAxis : public Command {

        public:
            MoveCommandYAxis(float increament_value = 0.1);
            virtual ~MoveCommandYAxis();

            void execute(Shape::Shape* shape);
            void undo(Shape::Shape*  shape);

        private:

            float increament_value;
    };
};

#endif
