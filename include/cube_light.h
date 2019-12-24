#ifndef CUBE_LIGHT_H
#define CUBE_LIGHT_H



#include "shape.h"
#include <vector>

namespace OpenGL {
    class TextureHolder;
};

namespace Shape {

    class LightCube : public Shape{

        public:

            LightCube();
            virtual ~LightCube();

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        private:

            void init_mesh(float* vertices , int sizeof_vertices);

            OpenGL::TextureHolder* texture;

    };

};


#endif
