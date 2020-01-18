#ifndef MOVE_COMMAND_Z_AXIS_H
#define MOVE_COMMAND_Z_AXIS_H


#include "command.h"

namespace OpenGL {

    class MoveCommandZAxis : public Command {

        public:
            MoveCommandZAxis(float increament_value = 0.1);
            virtual ~MoveCommandZAxis();

            void execute(Shape::Shape* shape);
            void undo(Shape::Shape*  shape);

        private:

            float increament_value;
    };
};
#endif
