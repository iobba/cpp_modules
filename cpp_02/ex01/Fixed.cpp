# include "Fixed.hpp"

Fixed::Fixed () : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.value;
    return (*this);
}

Fixed::Fixed(const int int_val)
{
    std::cout << "Int constructor called" << std::endl;
    value = int_val << fractional_bits;
}

Fixed::Fixed(const float float_val)
{
    std::cout << "Float constructor called" << std::endl;
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