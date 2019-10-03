#include "shape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Shape {


    Shape::Shape(const Color& color, bool shape_3D):
        shape_3D(shape_3D),
        m_color(color){
        m_rotate = Rotate(Rotate::AXIS::X , 0);
    }


    void Shape::set_model_pos(const glm::vec3& pos) {

        model_pos = glm::mat4(1.0f);
        model_pos = glm::translate(model_pos , pos);
    }

    void Shape::draw(const glm::mat4& projection , const  glm::mat4 view) {

        // this needs to be refactor , can handle 3D and 2D graphics
        // in same engine !!


        m_shader->use();
        m_shader->setMat4("view" , view);
        m_shader->setMat4("projection" , projection);

        if(m_color.color_set)
            m_shader->setVec4("color" ,  glm::vec4(m_color.r , m_color.g , m_color.b , m_color.a));

        glm::mat4 model = glm::mat4(1.0);

        if(!shape_3D)  {


            if(m_rotate.axis == Rotate::AXIS::X)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(1.0f , 0.0f , 0.0f));

            else if(m_rotate.axis == Rotate::AXIS::Y)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(0.0f , 1.0f , 0.0f));


            else if(m_rotate.axis == Rotate::AXIS::Z)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(0.0f , 0.0f , 1.0f));

            m_shader->setMat4("model" ,  model);


        } else {

            model_pos = glm::rotate(model_pos ,
                    glm::radians(m_rotate.angle) ,
                        glm::vec3(
                        m_rotate.x,
                        m_rotate.y,
                        m_rotate.z )
                        );

            m_shader->setMat4("model" ,  model_pos);
        }



    }

}
