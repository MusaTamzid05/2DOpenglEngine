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

        float x;
        float y;
        float z;

        Rotate() {}
        Rotate(AXIS axis ,float  angle):axis(axis) , angle(angle) {}

        Rotate(float x , float y , float z , float angle)  {
            this->x = x;
            this->y = y;
            this->z = z;
            this->angle = angle;
        }
    };
};


#endif
