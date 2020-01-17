#ifndef MATERIAL_CUBE_H
#define MATERIAL_CUBE_H

#include "light_cube.h"
#include "material.h"
#include <vector>

namespace OpenGL {
    class Camera;
};

namespace Shape {


    class MaterialCube : public LightCube {

        public:


            MaterialCube(
                    Shape* src,
                    OpenGL::Camera* camera,
                    const Color& color);

            virtual ~MaterialCube() {}

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        protected:


            Material material;
            OpenGL::Camera* m_camera;



    };
};


#endif
