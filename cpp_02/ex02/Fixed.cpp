# include "Fixed.hpp"

Fixed::Fixed () : value(0) {}

Fixed::~Fixed (){}

int Fixed::getRawBits(void) const
{
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.value;
    return (*this);
}

Fixed::Fixed(const int int_val)
{
    value = int_val << fractional_bits;
}

Fixed::Fixed(const float float_val)
{
    value = roundf(float_val * (1 << fractional_bits));
}

float Fixed::toFloat( void ) const
{
    float f = (float) value / (1 << fractional_bits);
    return(f);
}

int Fixed::toInt( void ) const
{
    return (value >> fractional_bits);
}

std::ostream& operator<<(std::ostream& outout_stream, const Fixed& fixed)
{
    outout_stream << fixed.toFloat();
    return (outout_stream);
}

bool Fixed::operator > (const Fixed& f2) const
{
    return (value > f2.value);
}

bool Fixed::operator >= (const Fixed& f2) const
{
    return (value >= f2.value);
}

bool Fixed::operator < (const Fixed& f2) const
{
    return (value < f2.value);
}

bool Fixed::operator <= (const Fixed& f2) const
{
    return (value <= f2.value);
}

bool Fixed::operator == (const Fixed& f2) const
{
    return (value == f2.value);
}

bool Fixed::operator != (const Fixed& f2) const
{
    return (value != f2.value);
}

Fixed Fixed::operator + (const Fixed& other) const
{
    Fixed sum;
    sum.value = value + other.value;
    return (sum);
}

Fixed Fixed::operator - (const Fixed& other) const
{
    Fixed sub;
    sub.value = value - other.value;
    return (sub);
}

Fixed Fixed::operator / (const Fixed& other) const
{
    Fixed div;
    div.value = roundf(((float) value / other.value) * (1 << fractional_bits));
    return (div);
}

Fixed Fixed::operator * (const Fixed& other) const
{
    Fixed mult;
    mult.value = value * other.value / (1 << fractional_bits);
    return (mult);
}

Fixed&  Fixed::operator++()
{
    value += 1;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed tmp = *this;
    value += 1;
    return (tmp);
}

Fixed&  Fixed::operator--()
{
    value -= 1;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed tmp = *this;
    value -= 1;
    return (tmp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}