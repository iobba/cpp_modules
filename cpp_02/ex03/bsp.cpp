#include "Point.hpp"

Fixed abs_val(Fixed a)
{
    if (a < 0)
        return (a * Fixed(-1));
    return (a);
}

Fixed   calculate_area(Point const a, Point const b, Point const c)
{
    Fixed   area = a.get_x() * (b.get_y() - c.get_y()) +
            b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y());

    return (abs_val(area) / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed f_area = calculate_area(point, a, b);
    Fixed s_area = calculate_area(point, a, c);
    Fixed l_area = calculate_area(point, b, c);
    Fixed real_area = calculate_area(a, b, c);
    Fixed sum = f_area + s_area + l_area;

    if (f_area.getRawBits() == 0 || s_area.getRawBits() == 0 || l_area.getRawBits() == 0)
        return (0);
    if (sum == real_area)
        return (1);
    return (0);
}