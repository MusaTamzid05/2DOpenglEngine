#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <vector>

namespace Shape {

    class Circle : public Shape{

        public:

            Circle(int x , int y , int c_radius);
            virtual ~Circle();

            void update();

        private:

            std::vector<float> vertices;

            virtual void draw_object();
            void init_mesh();
            void init_circle_vertices();

            int number_vertices;;
            int number_sides;;

            float x;
            float y;
            float radius;


    };
};

#endif
