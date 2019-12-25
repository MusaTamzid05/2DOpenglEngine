#ifndef ROTATE_H
#define ROTATE_H

#include <iostream>

namespace Shape {

    struct Rotate {

        enum AXIS {
            X,
            Y,
            Z
        };

        float angle;
        AXIS axis;

        Rotate(AXIS axis ,float  angle):
            axis(axis) , 
            angle(angle){}




    };


    std::ostream& operator<<(std::ostream& out , const Rotate& rotate);
};


#endif
