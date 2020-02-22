#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <string>
#include <map>

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

    struct TextureData {
        TextureData(
                unsigned int id ,
                int width ,
                int height,
                int nr_components
                );

        int width;
        int height;
        int nr_components;
        unsigned int id;

        void bind(int index);
    };

    class TextureManager {

        public:
            TextureManager() {}
            virtual ~TextureManager() {}

            void add(const std::string& texture_name , const std::string& texture_path);
            TextureData* get(const std::string& texture_name);

            void show();

        private:

            std::map<std::string , TextureData*> textures;
    };
};
#endif
