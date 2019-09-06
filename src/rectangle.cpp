#include "rectangle.h"

namespace Shape {

    Rectangle::Rectangle() {

        // top right
        vertices.push_back(0.5);
        vertices.push_back(0.5);
        vertices.push_back(0.0);


        // bottom right
        vertices.push_back(0.5);
        vertices.push_back(-0.5);
        vertices.push_back(0.0);


        // bottom left
        vertices.push_back(-0.5);
        vertices.push_back(-0.5);
        vertices.push_back(0.0);


        // top left
        vertices.push_back(-0.5);
        vertices.push_back(0.5);
        vertices.push_back(0.0);


        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(3);

        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(3);


        m_shader = new Shader("../shaders/basic.vs" , "../shaders/basic.fs");
        init_mesh();
    }




    Rectangle::~Rectangle() {

    }


    void Rectangle::init_mesh() {

        glGenVertexArrays(1 , &VAO);
        glGenBuffers(1 , &VBO);
        glGenBuffers(1 , &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER , VBO);

        glBufferData(
                GL_ARRAY_BUFFER ,
                vertices.size() * sizeof(unsigned int),
                &vertices[0],
                GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , indices.size() * sizeof(unsigned int)  , &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float) , (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER , 0);
        glBindVertexArray(0);

    }

    void Rectangle::draw() {

        Shape::draw();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , 0);
    }


    void Rectangle::update() {

    }


};
