#ifndef COLOR_H
#define COLOR_H

namespace Shape {

    struct Color {
        Color(float r , float g , float b , float a = 1.0):
            r(r),
            g(g),
            b(b),
            a(a) {}

        float r;
        float g;
        float b;
        float a;

    };
};
#endif
