#include "display.h"
#include "triangle.h"
#include "rectangle.h"
#include "cube.h"
#include <iostream>
#include "rotate.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL {

    Display::Display(int width , int height , const std::string& title):
    width(width),
    height(height){

        init_window(title);
        Shape::Shape* shape = new Shape::Cube();
        shapes.push_back(shape);
        
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

            handle_input();
            update();
            render();
        }
    }


    void Display::handle_input() {

        if(glfwGetKey(m_window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window , true);
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
                glm::radians(45.0f),
                 (float)width / (float)height,
                 0.1f,
                 100.0f
                );

        view = glm::translate(view , glm::vec3(0.0f , 0.0f , -3.0f));



        for(Shape::Shape* shape : shapes)
            shape->draw(projection , view);

        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }

};
