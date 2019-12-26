#ifndef SPECULAR_H
#define SPECULAR_H


#include "light_cube.h"
#include <vector>

namespace OpenGL {
    class Camera;
};

namespace Shape {


    class SpecularCube : public LightCube {

        public:


            SpecularCube(
                    Shape* src,
                    OpenGL::Camera* camera,
                    float specular_strength,
                    const Color& color);

            virtual ~SpecularCube() {}

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        protected:

            OpenGL::Camera* m_camera;
            float specular_strength;


    };
};

#endif
