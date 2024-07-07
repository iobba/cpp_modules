#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
        int value;
        static const int fractional_bits = 8;
    public:
        Fixed ();
        Fixed(const Fixed& other);
        Fixed(const int int_val);
        Fixed(const float float_val);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed ();
};

std::ostream& operator<<(std::ostream& outout_stream, const Fixed& fixed);


# endif