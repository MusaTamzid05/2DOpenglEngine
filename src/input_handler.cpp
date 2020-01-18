#include "input_handler.h"
#include "move_command_x_axis.h"
#include "move_command_y_axis.h"
#include "move_command_z_axis.h"
#include "command.h"


namespace OpenGL {

    InputHandler::InputHandler() {
        commands.insert(std::make_pair(GLFW_KEY_KP_4 , new MoveCommandXAxis()));
        commands.insert(std::make_pair(GLFW_KEY_KP_6 , new MoveCommandXAxis(0.1)));
        commands.insert(std::make_pair(GLFW_KEY_KP_8 , new MoveCommandYAxis()));
        commands.insert(std::make_pair(GLFW_KEY_KP_2 , new MoveCommandYAxis(-0.1)));
        commands.insert(std::make_pair(GLFW_KEY_KP_7 , new MoveCommandZAxis(-0.1)));
        commands.insert(std::make_pair(GLFW_KEY_KP_9 , new MoveCommandZAxis()));
    }

    Command* InputHandler::handle_input(int key) {
        return commands[key];
    }
};
