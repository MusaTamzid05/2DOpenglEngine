#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "color.h"
#include <vector>

namespace Shape {

    class Triangle : public Shape{

        public:

            Triangle(const Color& color);
            virtual ~Triangle();

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        private:

            std::vector<float> vertices;

            void init_mesh();

    };
};

#endif
