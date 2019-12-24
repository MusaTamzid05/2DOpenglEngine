#ifndef LIGHT_CUBE_H
#define LIGHT_CUBE_H

#include "shape.h"
#include <vector>

namespace OpenGL {
    class TextureHolder;
};

namespace Shape {

    class LightCube : public Shape{

        public:

            LightCube(const Color& color = Color());
            virtual ~LightCube();

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        private:

            void init_mesh(float* vertices , int sizeof_vertices);

            OpenGL::TextureHolder* texture;

    };
};
#endif
