#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include "shader.h"


namespace Shape {

    class Shape {

        public:

            Shape() {}
            virtual ~Shape() { delete m_shader;}

            virtual void draw() = 0;
            virtual void update() = 0;

            void set_pos(const TwoD::Vector& pos) { m_pos = pos; }
            void set_pos(int x , int y) { m_pos = TwoD::Vector(x , y); }
            
            TwoD::Vector get_pos() { return m_pos; }

        protected:
            
            TwoD::Vector m_pos;
            Shader* m_shader;

            unsigned int VAO;
            unsigned int VBO;
            unsigned int EBO;

            virtual void init_mesh() {}


    };
};

#endif 
