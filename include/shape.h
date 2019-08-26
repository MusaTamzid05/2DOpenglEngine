#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"
#include "shader.h"
#include "color.h"


namespace Shape {

    class Shape {

        public:

            Shape();
            virtual ~Shape() { delete m_shader;}

            virtual void draw();
            virtual void update() = 0;

            void set_pos(const TwoD::Vector& pos) { m_pos = pos; }
            void set_pos(int x , int y) { m_pos = TwoD::Vector(x , y); }
            void set_size(const TwoD::Vector& size) {m_size = size;}
            
            TwoD::Vector get_pos() { return m_pos; }

            void set_rotate(float rotate) { this->rotate = rotate; }
            void set_color(const Color& color) { m_color = color; }

        protected:
            
            virtual void draw_object() = 0;

            void draw_2d_pos();
            bool first_draw;
            float rotate;
            TwoD::Vector m_pos;
            TwoD::Vector m_size;

            Color m_color;


            Shader* m_shader;

            unsigned int VAO;
            unsigned int VBO;
            unsigned int EBO;

            virtual void init_mesh() {}


    };
};

#endif 
