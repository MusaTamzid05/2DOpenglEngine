#ifndef COMMAND_H
#define COMMAND_H

#include "shape.h"

namespace OpenGL {

    class Command {

        public:
            Command() {}
            virtual ~Command() {}

            virtual void execute(Shape::Shape* shape) = 0;
            virtual void undo(Shape::Shape* shape) = 0;

    };

};

#endif
