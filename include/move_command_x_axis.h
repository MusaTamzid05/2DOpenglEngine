#ifndef MOVE_COMMAND_X_AXIS_H
#define MOVE_COMMAND_X_AXIS_H

#include "command.h"

namespace OpenGL {

    class MoveCommandXAxis : public Command {

        public:
            MoveCommandXAxis(float increament_value = -0.1);
            virtual ~MoveCommandXAxis();

            void execute(Shape::Shape* shape);
            void undo(Shape::Shape*  shape);

        private:

            float increament_value;
    };
};

#endif
