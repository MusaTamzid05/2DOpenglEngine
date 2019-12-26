#ifndef AMBIENT_CUBE_H
#define AMBIENT_CUBE_H

#include "light_cube.h"
#include <vector>

namespace Shape {


    class AmbientCube : public LightCube {

        public:


            AmbientCube(
                    Shape* src,
                    const Color& color,
                    float ambient_strength);

            virtual ~AmbientCube() {}

            void draw(const glm::mat4& projection , const  glm::mat4 view);
            void update();

        protected:

            float ambient_strength;


    };
};

#endif
