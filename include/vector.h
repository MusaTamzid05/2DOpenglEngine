#ifndef VECTOR_H
#define VECTOR_H


namespace TwoD {

    struct Vector {

        Vector(int x = 0 , int y = 0);

        bool is_zero();
        int x;
        int y;
    };



}

#endif
