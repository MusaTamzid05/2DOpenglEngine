#include "display.h"
#include "triangle.h"
#include "rectangle.h"
#include "ambient_cube.h"
#include "material_cube.h"
#include "cube.h"
#include "const.h"
#include "camera.h"
#include <iostream>
#include "rotate.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace OpenGL {

    Camera* Display::m_camera = new Camera(glm::vec3(0.0f , 0.0f , 7.0f));
    bool Display::firstMouse = true;
    float Display::lastX = WIDTH / 2;
    float Display::lastY = HEIGHT / 2;


    Display::Display( const std::string& title):
    width(WIDTH),
    height(HEIGHT),
    deltaTime(0.0f),
    lastFrame(0.0f)
    {

        init_window(title);

        Shape::Cube* cube = new Shape::Cube(Shape::Color(1.0 , 1.0 , 1.0));
        cube->set_rotate(new Shape::Rotate(Shape::Rotate::AXIS::X, 139));
        cube->set_pos(glm::vec3(1.0 , 0.0 , 2.0));
        cube->set_color(Shape::Color(1.0 , 0.0 , 0.0));
        shapes.push_back(cube);


        shapes.push_back(
                new Shape::MaterialCube(
                    cube,
                    m_camera,
                    Shape::Color(0.0f , 1.0f , 0.0f)
                    )
                );


        
    }

    Display::~Display() {

        if(m_window)
            glfwTerminate();
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

    }

    void Display::update() {

        for(Shape::Shape* shape : shapes)  {
            shape->update();
        }
    }

    void Display::render() {

        glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // this should be inside loop, will
        // change it as soon as we have a camera
        
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
