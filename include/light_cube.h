#ifndef LIGHT_CUBE_H
#define LIGHT_CUBE_H

#include "shape.h"
#include <vector>

namespace OpenGL {
    class TextureHolder;
};

namespace Shape {


    class LightCube : public Shape {

        public:


            LightCube(
                    const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path,
                    Shape* src,
                    const Color& color = Color());


            LightCube() {}
            virtual ~LightCube();

            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);
            virtual void update();

        protected:

            virtual void init_mesh(float* vertices , int sizeof_vertices);

            OpenGL::TextureHolder* texture;
            Shape* src;


    };
};
#endif
