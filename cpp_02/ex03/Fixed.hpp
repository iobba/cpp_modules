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

        Fixed& operator = (const Fixed& other);

        bool operator > (const Fixed& f2) const;
        bool operator >= (const Fixed& f2) const;
        bool operator < (const Fixed& f2) const;
        bool operator <= (const Fixed& f2) const;
        bool operator == (const Fixed& f2) const;
        bool operator != (const Fixed& f2) const;

        Fixed operator + (const Fixed& other) const;
        Fixed operator - (const Fixed& other) const;
        Fixed operator / (const Fixed& other) const;
        Fixed operator * (const Fixed& other) const;

        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        static Fixed& min(Fixed& f1, Fixed& f2);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed ();
};

std::ostream& operator<<(std::ostream& outout_stream, const Fixed& fixed);


# endif