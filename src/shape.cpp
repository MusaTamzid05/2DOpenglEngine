#include "shape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Shape {



    Shape::Shape() {
        m_color = Color(1.0 , 0.5 , 0.2 , 1.0); 
        m_rotate = Rotate(Rotate::AXIS::X , 0);
    }


    void Shape::draw() {
        m_shader->use();
        m_shader->setVec4("color" ,  glm::vec4(m_color.r , m_color.g , m_color.b , m_color.a));

        glm::mat4 transform = glm::mat4(1.0);

        if(m_rotate.axis == Rotate::AXIS::X)
            transform = glm::rotate(transform , m_rotate.angle , glm::vec3(1.0f , 0.0f , 0.0f));

        else if(m_rotate.axis == Rotate::AXIS::Y)
            transform = glm::rotate(transform , m_rotate.angle , glm::vec3(0.0f , 1.0f , 0.0f));


        else if(m_rotate.axis == Rotate::AXIS::Z)
            transform = glm::rotate(transform , m_rotate.angle , glm::vec3(0.0f , 0.0f , 1.0f));


        m_shader->setMat4("model" ,  transform);
    }

}
