#include "triangle.h"
#include <iostream>

namespace Shape {

    Triangle::Triangle() {

        // left
        vertices.push_back(-0.5);
        vertices.push_back(-0.5);
        vertices.push_back(0.0f);


        // right
        vertices.push_back(0.5);
        vertices.push_back(-0.5);
        vertices.push_back(0.0f);


        // top
        vertices.push_back(0.0);
        vertices.push_back(0.5);
        vertices.push_back(0.0f);

        m_shader = new Shader("../shaders/basic.vs" , "../shaders/basic.fs");
        init_mesh();

    }

    Triangle::~Triangle() {

    }

    void Triangle::init_mesh() {

        glGenVertexArrays(1 , &VAO);
        glGenBuffers(1 , &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER , VBO);
        glBufferData(
                GL_ARRAY_BUFFER ,
                vertices.size() * sizeof(unsigned int),
                &vertices[0],
                GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER , 0);
        glBindVertexArray(0);

    }

    void Triangle::draw() {

        m_shader->use();
        m_shader->setVec4("color" ,  glm::vec4(m_color.r , m_color.g , m_color.b , m_color.a));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES , 0 , 3);
    }


    void Triangle::update() {

    }
};
