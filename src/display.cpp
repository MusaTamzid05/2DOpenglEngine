#include "display.h"
#include "triangle.h"
#include "rectangle.h"
#include "cube.h"
#include <iostream>
#include "rotate.h"

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

    Display::Display(int width , int height , const std::string& title):
    width(width),
    height(height){

        init_window(title);

        for(unsigned int i = 0 ; i < 10 ; i++) {
            Shape::Shape* shape = new Shape::Cube();
            shapes.push_back(shape);
        }
        
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

        for(unsigned int i = 0 ; i < shapes.size() ; i++)  {

            shapes[i]->draw(projection , view);

            glm::mat4 model = glm::mat4(1.0f);
            float angle = 20.0f * i;
            Shape::Rotate rotate = Shape::Rotate(1.0f ,
                    0.3f,
                    0.5f,
                    angle);
            shapes[i]->set_rotate(rotate);
            shapes[i]->set_model_pos(cubePositions[i]);


            
        }

        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }

};
