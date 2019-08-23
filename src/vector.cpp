#include "vector.h"

namespace TwoD {
    Vector::Vector(int x , int y):x(x),y (y) {}

    bool Vector::is_zero() {
        return x == 0.0f && y == 0.0f;
    }
};
