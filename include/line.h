#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "vector.h"
#include <vector>


namespace Shape {
    class Rectangle;


    class Line : public Shape {

        public:

            Line(const TwoD::Vector& from , const TwoD::Vector& to);
            virtual ~Line();


            void update();
            void draw();

        private:

            std::vector<TwoD::Vector> get_bresenham_points(const TwoD::Vector& from , const TwoD::Vector& to);

            void draw_object() {}
            void init_mesh();

            std::vector<Rectangle*> rectangles;

    };
};
#endif
