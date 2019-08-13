#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace OpenGL {


    class Display {

        public:

            Display(int width = 640 , int height = 480, const std::string& title = "Window");
            virtual ~Display();

            void run();

        private:

            void glfw_init();
            GLFWwindow* m_window;

            static void frame_buffer_size_callback(
                    GLFWwindow* window,
                    int width,
                    int height
                    );

            void handle_input();
            void render();
    };

};

#endif
