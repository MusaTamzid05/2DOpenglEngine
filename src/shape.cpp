#include "shape.h"
#include "consts.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Shape {

    Shape::Shape():
        rotate(0.0) ,
        m_pos(0.0f , 0.0f),
        m_size(0.0f , 0.0f),
        m_color(1.0f , 1.0f , 1.0f),
       first_draw(true){


        }

    void Shape::draw() {

        if(m_shader == nullptr) {
            std::cerr << "Shader is not initialize.\n";
            return;
        }

        m_shader->use();

        draw_2d_pos();
        draw_object();
    }

    void Shape::draw_2d_pos() {


        if(first_draw) {

            first_draw = false;

            glm::mat4 projection = glm::ortho(
                    0.0f,
                    static_cast<float> (Const::WIDTH),
                    static_cast<float> (Const::HEIGHT),
                    0.0f,
                    -1.0f,
                    1.0f
                    );

            m_shader->setMat4("projection" , projection);
        }


        glm::mat4 model(1.0);

        if(m_size.is_zero()) 
            std::cout << "Warning size is still zero !!\n";

        model = glm::translate(model , glm::vec3(m_pos.x , m_pos.y ,  0.0f));


        // move center to the object middle.
        model = glm::translate(model , glm::vec3(0.5 * m_size.x , 0.5 * m_size.y , 0.0f));


        // rotate
        //model = glm::rotate(model , rotate , glm::vec3(0.0f , 0.0f , 0.0f));


        // move it back.
        model = glm::translate(model , glm::vec3(-0.5 * m_size.x , - 0.5 * m_size.y , 0.0f));
        // scale
        model = glm::scale(model , glm::vec3(m_size.x , m_size.y, 1.0f));


        // Dont forget to sets this value in the shader.
        

        m_shader->setMat4("model" , model);
        m_shader->setVec3("color" , glm::vec3(m_color.r , m_color.g , m_color.b ));

    }

};

