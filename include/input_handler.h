#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "command.h"


#include <map>

namespace OpenGL {


    class InputHandler {

        public:
            InputHandler();
            Command* handle_input( int key);

        private:
            std::map<int ,Command*> commands;
    };
};


#endif
