#include "line.h"
#include "rectangle.h"
#include <exception>

namespace Shape {

    Line::Line( const TwoD::Vector& from , const TwoD::Vector& to ) {
        get_bresenham_points(from , to);
        std::vector<TwoD::Vector> points = get_bresenham_points(from , to);

        for(TwoD::Vector point : points) {
            Rectangle* rect = new Rectangle();
            rect->set_pos(point.x , point.y);
            rect->set_size(TwoD::Vector(1 , 1));
            rectangles.push_back(rect);

        }

        std::cout << "we have a shape.\n";
    }

    Line::~Line() {

    }

    void Line::update() {

    }

    void Line::draw() {
        
        for(Rectangle* rect : rectangles)
            rect->draw();
    } 

    void Line::init_mesh() {

    }

    
    
    std::vector<TwoD::Vector> Line::get_bresenham_points(const TwoD::Vector& from , const TwoD::Vector& to) {


        if(from.x >  to.x) 
            throw std::runtime_error("Drawing line error : From cordinate is greater than to cordinate!!Try to swap the 'x' value");
        
        std::vector<TwoD::Vector> points;

        int m_new = 2 * (to.y  - from.y);
        int slop_error_new = m_new - (to.x- from.x);

        for(int x = from.x, y  = from.y ; x <= to.x; x++) {
            slop_error_new += m_new;

            points.push_back(TwoD::Vector(x , y));

            if(slop_error_new >= 0) {
                y++;
                slop_error_new -= 2 * (to.x - from.x);
            }
        }

        return points;
    }
};
