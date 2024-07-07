# ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class   Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float x_, const float y_);
        Point(const Point& other);
        Point& operator = (const Point& other);
        Fixed get_x() const;
        Fixed get_y() const;
        ~Point();

};
bool bsp( Point const a, Point const b, Point const c, Point const point);


# endif