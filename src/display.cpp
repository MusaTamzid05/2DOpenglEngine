#include "display.h"
#include "triangle.h"
#include "rectangle.h"
#include "input_handler.h"
#include "ambient_cube.h"
#include "material_cube.h"
#include "direction_light_cube.h"
#include "cube.h"
#include "const.h"
#include "camera.h"
#include <iostream>
#include "rotate.h"
#include "texture_holder.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::vec3 cubePositions[] = {
	glm::vec3( 0.0f,  0.0f,  0.0f),
	glm::vec3( 2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3( 2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3( 1.3f, -2.0f, -2.5f),
	glm::vec3( 1.5f,  2.0f, -2.5f),
	glm::vec3( 1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
};

namespace OpenGL {

    Camera* Display::m_camera = new Camera(glm::vec3(0.0f , 0.0f , 7.0f));
    bool Display::firstMouse = true;
    float Display::lastX = WIDTH / 2;
    float Display::lastY = HEIGHT / 2;


    Display::Display( const std::string& title):
    width(WIDTH),
    height(HEIGHT),
    deltaTime(0.0f),
    lastFrame(0.0f),
    input_handler(new InputHandler())
    {

        init_window(title);

        Shape::Cube* cube = new Shape::Cube(Shape::Color(1.0 , 1.0 , 1.0));
        cube->set_pos(glm::vec3(1.0 , 0.0 , 2.0));
        cube->set_color(Shape::Color(1.0 , 0.0 , 0.0));
        shapes.push_back(cube);

        texture_manager = new TextureManager();
        texture_manager->add("container2" , "../res/container2.png");
        texture_manager->add("container2_specular" , "../res/container2_specular.png");

        texture_manager->show();

        std::vector<std::string> texture_names;
        texture_names.push_back("container2");
        texture_names.push_back("container2_specular");

        int total_cubes = 10;
        float angle = 20.0;

        for(unsigned int i = 0 ; i < total_cubes ; i++)  {
            Shape::Shape* shape = new Shape::DirectionLightCube(
                        cube,
                        m_camera,
                        "../shaders/direction_light_cube.vs",
                        "../shaders/direction_light_cube.fs",
                        texture_manager,
                        texture_names
                        );
            shape->set_rotate(new Shape::Rotate(angle + i , cubePositions[i]));
            shapes.push_back(shape);
        }

    }

    Display::~Display() {

        if(m_window)
            glfwTerminate();

        delete texture_manager;
    }

    void Display::init_window( const std::string& title ) {

        glfw_init();

        m_window = glfwCreateWindow(
                width ,
                height ,
                title.c_str() ,
                nullptr,
                nullptr);

        if(m_window == nullptr) {
            std::cerr << "Could not create glfw window.\n";
            glfwTerminate();
        }

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window , frame_buffer_size_callback);
        glfwSetCursorPosCallback(m_window , mouse_callback);
        glfwSetScrollCallback(m_window , scroll_callback);


        // capture mouse

        glfwSetInputMode(m_window , GLFW_CURSOR , GLFW_CURSOR_DISABLED);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize glad.\n";
            exit(1);
        }


        glEnable(GL_DEPTH_TEST);
    }

    void Display::glfw_init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        std::cout << "glfw initialize.\n";
    }


    void Display::frame_buffer_size_callback(
            GLFWwindow* window,
            int width,
            int height
            ) {
        glViewport(0 , 0 , width , height);
    }

    void Display::run() {

        while(!glfwWindowShouldClose(m_window)) {

            update_fps();
            handle_input();
            update();
            render();
        }
    }


    void Display::handle_input() {

        if(glfwGetKey(m_window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window , true);


        if(glfwGetKey(m_window , GLFW_KEY_W) == GLFW_PRESS)
            m_camera->ProcessKeyboard(FORWARD , deltaTime);

        if(glfwGetKey(m_window , GLFW_KEY_S) == GLFW_PRESS)
            m_camera->ProcessKeyboard(BACKWARD, deltaTime);

        if(glfwGetKey(m_window , GLFW_KEY_A) == GLFW_PRESS)
            m_camera->ProcessKeyboard(LEFT, deltaTime);

        if(glfwGetKey(m_window , GLFW_KEY_D) == GLFW_PRESS)
            m_camera->ProcessKeyboard(RIGHT, deltaTime);

        // this fucking code can be lot simpler if we ignore
        // the command pattern.


        if(glfwGetKey(m_window , GLFW_KEY_KP_4)) {
            Command* left_command = input_handler->handle_input(GLFW_KEY_KP_4);
            left_command->execute(shapes[0]);
        }  else if(glfwGetKey(m_window , GLFW_KEY_KP_6)) {
            Command* right_command = input_handler->handle_input(GLFW_KEY_KP_6);
            right_command->execute(shapes[0]);
        } else if(glfwGetKey(m_window , GLFW_KEY_KP_8)) {
            Command* up_command = input_handler->handle_input(GLFW_KEY_KP_8);
            up_command->execute(shapes[0]);
        }  else if(glfwGetKey(m_window , GLFW_KEY_KP_2)) {
            Command* down_command = input_handler->handle_input(GLFW_KEY_KP_2);
            down_command->execute(shapes[0]);
        } else if(glfwGetKey(m_window , GLFW_KEY_KP_7)) {
            Command* command = input_handler->handle_input(GLFW_KEY_KP_7);
            command->execute(shapes[0]);
        }  else if(glfwGetKey(m_window , GLFW_KEY_KP_9)) {
            Command* command = input_handler->handle_input(GLFW_KEY_KP_9);
            command->execute(shapes[0]);
        }

    }

    void Display::update() {

        for(Shape::Shape* shape : shapes)  {
            shape->update();
        }
    }

    void Display::render() {

        //glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClearColor(0.0f , 0.0f , 0.0f , 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        projection = glm::perspective(
                glm::radians(m_camera->Zoom),
                 (float)width / (float)height,
                 0.1f,
                 100.0f
                );

        view = m_camera->GetViewMatrix();

        for(unsigned int i = 0 ; i < shapes.size() ; i++)  {
            shapes[i]->set_pos(cubePositions[i]);
            shapes[i]->draw(projection , view);
        }

        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }


    void Display::mouse_callback(GLFWwindow* window,
                    double xpos,
                    double ypos) {

        if(firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;

        lastX = xpos;
        lastY = ypos;
        m_camera->ProcessMouseMovement(xoffset , yoffset);
    }


    void Display::scroll_callback(GLFWwindow* window,
                    double xoffset,
                    double yoffset) {

        m_camera->ProcessMouseScroll(yoffset);
    }

    void Display::update_fps() {

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

};
