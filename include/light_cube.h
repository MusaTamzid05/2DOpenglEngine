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


            LightCube(Shape* src) { this->src = src; }
            virtual ~LightCube();

            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);
            virtual void update();

        protected:

            void init(float* vertices ,
                    int sizeof_vertices ,
                    const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path
                    );


            virtual void init_mesh(float* vertices , int sizeof_vertices);

            Shape* src;


    };
};
#endif
