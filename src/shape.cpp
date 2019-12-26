#include "shape.h"
#include "util.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Shape {


    Shape::Shape(const Color& color, bool shape_3D):
        shape_3D(shape_3D),
        m_rotate(nullptr),
        m_color(color){

        model = glm::mat4(1.0f);
        set_pos(glm::vec3(0.0,0.0,0.0));
    }


    void Shape::set_pos(const glm::vec3& pos) {


        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        pos3D = pos;

    }

    void Shape::draw(const glm::mat4& projection , const  glm::mat4 view) {

        // we have properly broke the 2D engine for this draw

        m_shader->use();
        m_shader->setMat4("view" , view);
        m_shader->setMat4("projection" , projection);

        if(m_color.color_set)
            m_shader->setVec4("color" ,  glm::vec4(m_color.r , m_color.g , m_color.b , m_color.a));

        glm::mat4 model_after_rotate = model;

        if(m_rotate)  {
            if(m_rotate->axis == Rotate::AXIS::X)
                model_after_rotate = glm::rotate(model_after_rotate , m_rotate->angle , glm::vec3(1.0f , 0.0f , 0.0f));

            else if(m_rotate->axis == Rotate::AXIS::Y)
                model_after_rotate = glm::rotate(model_after_rotate , m_rotate->angle , glm::vec3(0.0f , 1.0f , 0.0f));


            else if(m_rotate->axis == Rotate::AXIS::Z)
                model_after_rotate = glm::rotate(model_after_rotate , m_rotate->angle , glm::vec3(0.0f , 0.0f , 1.0f));
        }


        m_shader->setMat4("model" ,  model_after_rotate);



    }

}
