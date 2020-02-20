#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <string>

class Shader;


namespace OpenGL {

    class TextureHolder {

        public:
            TextureHolder(const std::string& path , Shader* shader);
            virtual ~TextureHolder() {}
            void bind();

        private:

            unsigned int id;
            int width;
            int height;
            int nr_components;

            Shader* m_shader;

    };
};
#endif
