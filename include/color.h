#ifndef COLOR_H
#define COLOR_H

namespace Shape {

    struct Color {

        float r;
        float g;
        float b;
        float a;

        bool color_set;

        void set_color( float r , float g , float b , float a = 1.0 ){
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
            color_set = true;
        }

        Color():color_set(false) {}

        Color(float r , float g , float b , float a = 1.0):
        r(r) , g(g) , b(b) , a(a), color_set(true){}



    };
};

#endif
