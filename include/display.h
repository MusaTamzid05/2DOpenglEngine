#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "shape.h"

namespace OpenGL {


    class Camera;
    class InputHandler;
    class TextureManager;


    class Display {

        public:

            Display(const std::string& title = "Window");
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

            static void  mouse_callback(GLFWwindow* window,
                    double xpos,
                    double ypos);
            static void scroll_callback(GLFWwindow* window , double xoffset , double yoffset);

            void handle_input();
            void render();
            void update_fps();
            void update();

            std::vector<Shape::Shape*> shapes;

            void init_window( const std::string& title );

            int width;
            int height;


            // for camera movement
            static bool firstMouse;
            static float lastX;
            static float lastY;

            static Camera* m_camera;


            // fps
            
            float deltaTime;
            float lastFrame;

            InputHandler* input_handler;
            TextureManager* texture_manager;

    };

};

#endif
