#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "shape.h"

namespace OpenGL {


    class Display {

        public:

            Display( const std::string& title = "Window");
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
            void update();

            std::vector<Shape::Shape*> shapes;

            void init_window( const std::string& title );
    };

};

#endif
