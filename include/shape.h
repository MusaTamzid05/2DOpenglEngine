#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include "shader.h"
#include "color.h"


namespace Shape {

    class Shape {

        public:

            Shape() { m_color = Color(1.0 , 0.5 , 0.2 , 1.0); }
            virtual ~Shape() { delete m_shader;}

            virtual void draw() = 0;
            virtual void update() = 0;

            void set_pos(const TwoD::Vector& pos) { m_pos = pos; }
            void set_pos(int x , int y) { m_pos = TwoD::Vector(x , y); }

            void set_color(const Color& color) { m_color = color; }
            
            TwoD::Vector get_pos() { return m_pos; }

        protected:
            
            TwoD::Vector m_pos;
            Shader* m_shader;

            unsigned int VAO;
            unsigned int VBO;
            unsigned int EBO;

            Color m_color;

            virtual void init_mesh() {}


    };
};

#endif 
