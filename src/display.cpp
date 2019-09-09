#include "display.h"
#include "line.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "consts.h"
#include <iostream>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace OpenGL {

    Display::Display( const std::string& title) {

        init_window( title);
        Shape::Shape* shape = new Shape::Circle(200 , 300 , 200);
        //shape->set_rotate(30);
        //shape->set_size(10);
        shapes.push_back(shape);

    
        //shapes.push_back(new Shape::Line(TwoD::Vector(0 , 0) , TwoD::Vector(800 , 600)));
    }

    Display::~Display() {

        if(m_window)
            glfwTerminate();
    }


    void Display::init_window( const std::string& title ) {

        glfw_init();

        m_window = glfwCreateWindow(
                Const::WIDTH,
                Const::HEIGHT,
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

        for(Shape::Shape* shape : shapes)
            shape->update();
    }

    void Display::render() {

        glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        for(Shape::Shape* shape : shapes)
            shape->draw();

        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }

};
