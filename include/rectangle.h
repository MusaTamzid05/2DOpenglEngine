#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <vector>

namespace Shape {

    class Rectangle : public Shape {

        public:
            Rectangle();
            virtual ~Rectangle();

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        private:

            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            void init_mesh();

    };

};

#endif
