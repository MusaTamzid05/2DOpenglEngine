#include "rectangle.h"


namespace Shape {

    Rectangle::Rectangle():Shape() {

        /*
         * TODO:  top y should be 1 and bottom y should be -1
         * for some reason here case is opposite,
         * Need to fix this bug.
         * */

        // top left
        vertices.push_back(-1.0);
        vertices.push_back(-1.0);
        vertices.push_back(0.0f);


        // top right
        vertices.push_back(1.0);
        vertices.push_back(1.0);
        vertices.push_back(0.0f);


        // bottom right
        vertices.push_back(1.0);
        vertices.push_back(-1.0);
        vertices.push_back(0.0f);

        // bottom left
        vertices.push_back(-1.0);
        vertices.push_back(1.0);
        vertices.push_back(0.0f);



        m_shader = new Shader("../shaders/basic.vs" , "../shaders/basic.fs");
        init_mesh();

        m_color = Color(0 , 1 , 0 , 0);
        m_size = TwoD::Vector(100,100);
        m_pos = TwoD::Vector(100 , 100);

    }

    Rectangle::~Rectangle() {

    }

    void Rectangle::init_mesh() {


        unsigned int indices[] = {
            0 , 1, 2 ,
            0 , 1, 3
        };


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
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(indices) , indices , GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER , 0);
        glBindVertexArray(0);

    }

    void Rectangle::draw_object() {

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT  , 0);
    }


    void Rectangle::update() {

    }
};
