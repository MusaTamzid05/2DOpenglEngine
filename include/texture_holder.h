#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <string>

class Shader;


namespace OpenGL {


    class TextureHolder {

        public:

            TextureHolder(const std::string& file_path , Shader* shader);
            virtual ~TextureHolder() {}

            void bind();

        private:

            void init();
            void load_image_opengl(const std::string& file_path);

            int width;
            int height;
            int nr_channels;

            unsigned int id;

            Shader* m_shader;

    };


};
#endif
