#include "circle.h"
#include <cmath>


namespace Shape {

    Circle::Circle( int x , int y , int c_radius) {
        init_circle_vertices();
        m_shader = new Shader("../shaders/basic.vs" , "../shaders/basic.fs");
        init_mesh();

        m_color = Color(0 , 1 , 0 , 0);
        m_size = TwoD::Vector(100,100);
        m_pos = TwoD::Vector(x, y);
        m_size = TwoD::Vector(c_radius , c_radius);


    }


    Circle::~Circle() {


    }

    void Circle::update() {


    }


    void Circle::init_mesh() {

        glGenVertexArrays(1 , &VAO);
        glGenBuffers(1 , &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER , VBO);
        glBufferData(
                GL_ARRAY_BUFFER ,
                vertices.size() * sizeof(float),
                &vertices[0],
                GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);


        glBindBuffer(GL_ARRAY_BUFFER , 0);
        glBindVertexArray(0);

    }

    void Circle::init_circle_vertices() {


        number_sides = 360;
        number_vertices = 2 * number_sides;

        float x = 0.0;
        float y = 0.0;
        float radius = 1.0;
        float double_pi = M_PI * 2;

        for(unsigned int i = 1 ; i < number_vertices ; i++) {
            vertices.push_back(x + (radius * cos(i * double_pi / number_sides)));
            vertices.push_back(x + (radius * sin(i * double_pi / number_sides)));
            vertices.push_back(0.0);
        }

        std::cout << "vertices created.\n";

    }


    void Circle::draw_object() {

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0 , number_vertices);

    }

};
