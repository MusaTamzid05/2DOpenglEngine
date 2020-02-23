#ifndef DIRECTION_LIGHT_CUBE_H
#define DIRECTION_LIGHT_CUBE_H

#include "texture_light_cube.h"

namespace Shape {

    class DirectionLightCube : public  TextureLightCube {

        public:

            DirectionLightCube(
                    Shape* src ,
                    OpenGL::Camera* camera,
                    const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path,
                    OpenGL::TextureManager* texture_manager,
                    std::vector<std::string> texture_names
                    );
            virtual ~DirectionLightCube() {}
            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);

    };
}

#endif
