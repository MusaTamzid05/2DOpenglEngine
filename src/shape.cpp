#include "shape.h"
#include "util.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Shape {


    Shape::Shape(const Color& color, bool shape_3D):
        shape_3D(shape_3D),
        m_color(color){
        m_rotate = Rotate(Rotate::AXIS::X , 0);

        model = glm::mat4(1.0f);
        set_pos(glm::vec3(0.0,0.0,0.0));
    }


    void Shape::set_pos(const glm::vec3& pos) {


        std::cout << "Setting pos.\n";
        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        pos3D = pos;
        Util::print_mat4(model);

    }

    void Shape::draw(const glm::mat4& projection , const  glm::mat4 view) {

        // this needs to be refactor , can not handle 3D and 2D graphics
        // in same engine !!


        m_shader->use();
        m_shader->setMat4("view" , view);
        m_shader->setMat4("projection" , projection);

        if(m_color.color_set)
            m_shader->setVec4("color" ,  glm::vec4(m_color.r , m_color.g , m_color.b , m_color.a));


        if(!shape_3D)  {

            glm::mat4 model = glm::mat4(1.0);

            if(m_rotate.axis == Rotate::AXIS::X)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(1.0f , 0.0f , 0.0f));

            else if(m_rotate.axis == Rotate::AXIS::Y)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(0.0f , 1.0f , 0.0f));


            else if(m_rotate.axis == Rotate::AXIS::Z)
                model = glm::rotate(model , m_rotate.angle , glm::vec3(0.0f , 0.0f , 1.0f));

            m_shader->setMat4("model" ,  model);


        } else {

            /*
            model = glm::rotate(model,
                    glm::radians(m_rotate.angle) ,
                        glm::vec3(
                        m_rotate.x,
                        m_rotate.y,
                        m_rotate.z )
                        );
                        */


            Util::print_mat4(model);
            m_shader->setMat4("model" ,  model);
        }



    }

}
