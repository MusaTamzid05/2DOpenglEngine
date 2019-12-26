#include "color.h"

namespace Shape {


    std::ostream& operator<<(std::ostream& out , const Color& color) {
        out << "Color : r = " <<  color.r << " , g =  " << color.g << " , b = " << color.b  << " , a = " << color.a;
        return out;
    }


};
