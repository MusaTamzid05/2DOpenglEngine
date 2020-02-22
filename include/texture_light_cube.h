#ifndef TEXTURE_LIGHT_CUBE_H
#define TEXTURE_LIGHT_CUBE_H


#include "shape.h"
#include "light_cube.h"
#include <vector>

#include "material.h"
#include "light_property.h"


namespace OpenGL {
    class Camera;
    class TextureManager;
    struct TextureData;
};



namespace Shape {

    class TextureLightCube : public LightCube {

        public:


            TextureLightCube(Shape* src ,
                    OpenGL::Camera* camera,
                    OpenGL::TextureManager* texture_manager,
                    const std::string& texture_name);

            TextureLightCube(Shape* src ,
                    OpenGL::Camera* camera,
                    OpenGL::TextureManager* texture_manager,
                    std::vector<std::string> texture_names);

            virtual ~TextureLightCube();

            virtual void draw(const glm::mat4& projection , const  glm::mat4 view);
            virtual void update();

        protected:


            void init_data(  
                    OpenGL::TextureManager* texture_manager,
                    std::vector<std::string> texture_names);

            virtual void init_mesh(float* vertices , int sizeof_vertices);

            Material material;
            OpenGL::Camera* m_camera;
            LightProperty light_property;



            void format_src_color(Color& src_color);
            std::vector<OpenGL::TextureData*> texture_data_list;

    };
};


#endif
