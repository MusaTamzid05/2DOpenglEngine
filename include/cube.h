#ifndef CUBE_H
#define CUBE_H

#include "shape.h"
#include <vector>

namespace Shape {

    class Cube : public Shape{

        public:

            Cube();
            virtual ~Cube();

            void draw();
            void update();

        private:

            void init_mesh(float* vertices , int sizeof_vertices);

    };
};
#endif
