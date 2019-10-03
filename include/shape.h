#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include "shader.h"
#include "color.h"
#include "rotate.h"


namespace Shape {

    class Shape {

        public:

            Shape(const Color& color = Color() , bool shape_3D = false);
            virtual ~Shape() { delete m_shader;}

            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);
            virtual void update() = 0;

            void set_pos(const TwoD::Vector& pos) { m_pos = pos; }
            void set_pos(int x , int y) { m_pos = TwoD::Vector(x , y); }

            void set_color(const Color& color) { m_color = color; }
            
            TwoD::Vector get_pos() { return m_pos; }


            void set_rotate(const Rotate& rotate ) {m_rotate = rotate;}

            void set_model_pos(const glm::vec3& pos);

        protected:
            
            TwoD::Vector m_pos;
            Shader* m_shader;
            Rotate m_rotate;


            glm::mat4 model_pos;

            unsigned int VAO;
            unsigned int VBO;
            unsigned int EBO;

            Color m_color;

            bool shape_3D; // to check if the shape is 3D in drawing

            virtual void init_mesh() {}


    };
};

#endif 
