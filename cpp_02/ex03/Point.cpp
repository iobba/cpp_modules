#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x_, const float y_) : x(x_), y(y_) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) 
{
    (void)other;
    return (*this);
}

Point::~Point (){}

Fixed Point::get_x() const
{
    return (this->x);
}

Fixed Point::get_y() const
{
    return (this->y);
}