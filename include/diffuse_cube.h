#ifndef DIFFUSE_CUBE_H
#define DIFFUSE_CUBE_H

#include "light_cube.h"
#include <vector>

namespace Shape {


    class DiffuseCube : public LightCube {

        public:


            DiffuseCube(
                    Shape* src,
                    const Color& color);

            virtual ~DiffuseCube() {}

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        protected:



    };
};


#endif
