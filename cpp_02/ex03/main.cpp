#include "Point.hpp"

int main ()
{
    Point const a(2.0, 4.0);
    Point const b(1.0, 1.0);
    Point const c(4.0, 1.0);
    Point const point(2, 3.9);
    if (bsp(a, b, c, point))
    {
        std::cout << "the point is inside the triangle abc : ";
        std::cout << "\033[32m" << "True" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "the point is not inside the triangle abc : ";
        std::cout << "\033[31m" << "False" << "\033[0m" << std::endl;
    }
}