#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <vector>

namespace Shape {

    class Triangle : public Shape{

        public:

            Triangle();
            virtual ~Triangle();

            void update();

        private:

            std::vector<float> vertices;

            virtual void draw_object();
            void init_mesh();

    };
};

#endif
