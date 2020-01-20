#ifndef TEXTURE_LIGHT_CUBE_H
#define TEXTURE_LIGHT_CUBE_H


#include "shape.h"
#include "light_cube.h"
#include <vector>

#include "material.h"
#include "light_property.h"


namespace OpenGL {
    class Camera;
};



namespace Shape {

    class TextureLightCube : public LightCube {

        public:


            TextureLightCube(Shape* src , OpenGL::Camera* camera);


            virtual ~TextureLightCube();

            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);
            virtual void update();

        protected:

            virtual void init_mesh(float* vertices , int sizeof_vertices);

            Material material;
            OpenGL::Camera* m_camera;
            LightProperty light_property;


    };
};


#endif