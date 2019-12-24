#ifndef CUBE_H
#define CUBE_H

#include "shape.h"
#include <vector>

namespace OpenGL {
    class TextureHolder;
};

namespace Shape {

    class Cube : public Shape{

        public:

            Cube(const Color& color = Color(1.0f , 1.0f , 1.0f));
            Cube(const std::string&  texture_path);
            virtual ~Cube();

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        private:


            void init();
            void init_mesh(float* vertices , int sizeof_vertices);

            OpenGL::TextureHolder* texture;

    };
};
#endif
