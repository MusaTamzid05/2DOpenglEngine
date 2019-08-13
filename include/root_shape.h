#ifndef SHAPE_H
#define SHAPE_H

#include "vector.h"


namespace Shape {

    class RootShape {

        public:

            RootShape() {}
            virtual ~RootShape() {}

            virtual void draw() = 0;
            virtual void update() = 0;

            void set_pos(const TwoD::Vector& pos) { m_pos = pos; }
            void set_pos(int x , int y) { m_pos = TwoD::Vector(x , y); }
            
            TwoD::Vector get_pos() { return m_pos; }

        protected:


            TwoD::Vector m_pos;

    };
};

#endif 
