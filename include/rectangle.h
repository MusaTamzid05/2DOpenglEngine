#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "shape.h"
#include <vector>

namespace Shape {

    class Rectangle : public Shape{

        public:

            Rectangle();
            virtual ~Rectangle();

            void update();

        private:

            std::vector<float> vertices;

            virtual void draw_object();
            void init_mesh();

    };
};

#endif
