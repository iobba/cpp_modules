# include "Fixed.hpp"

void    my_own_tests(void)
{
    Fixed a(1);
    Fixed b(2);

    if (a > b)
        std::cout << "a is greater than b" << std::endl;
    if (a >= b)
        std::cout << "a is greater than or equal to b" << std::endl;
    if (a < b)
        std::cout << "a is less than b" << std::endl;
    if (a <= b)
        std::cout << "a is less than or equal to b" << std::endl;
    if (a == b)
        std::cout << "a is equal to b" << std::endl;
    if (a != b)
        std::cout << "a is not equal to b" << std::endl;
    
    std::cout << "\n----------------------------------------------------\n\n" ;

    Fixed c;
    c = a + b;
    std::cout << "a + b = " << c << std::endl;
    c = a - b;
    std::cout << "a - b = " << c << std::endl;
    c = a * b;
    std::cout << "a * b = " << c << std::endl;
    c = a / b;
    std::cout << "a / b = " << c << std::endl;

    std::cout << "\n----------------------------------------------------\n\n" ;

    std::cout << "a++ = " << a++ << "   ---> a = " << a << std::endl;
    std::cout << "++a = " << ++a <<  "   ---> a  = " << a << std::endl;
    std::cout << "a-- = " << a-- << "   ---> a = " << a << std::endl;
    std::cout << "--a = " << --a <<  "   ---> a  = " << a << std::endl;

    std::cout << "\n----------------------------------------------------\n\n" ;

    const Fixed e(3);
    const Fixed f(4);

    std::cout << "min of (a b) is : " << Fixed::min(a, b) << std::endl;
    std::cout << "min of (e f) is : " << Fixed::min(e, f) << std::endl;
    std::cout << "max of (a b) is : " << Fixed::max(a, b) << std::endl;
    std::cout << "max of (e f) is : " << Fixed::max(e, f) << std::endl;
}

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // my_own_tests();
    return (0);
}
