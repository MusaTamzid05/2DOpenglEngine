#ifndef ROTATE_H
#define ROTATE_H

namespace Shape {

    struct Rotate {

        enum AXIS {
            X,
            Y,
            Z
        };

        float angle;
        AXIS axis;

        Rotate() {}
        Rotate(AXIS axis ,float  angle):axis(axis) , angle(angle) {}
    };
};


#endif
