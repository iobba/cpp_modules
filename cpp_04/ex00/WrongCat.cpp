#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "A WrongCAT has been created using default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "A WrongCat has been created using copy constructor" << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    this->type = other.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "A WrongCat has been destroyed" << std::endl;
}

void   WrongCat::makeSound() const
{
    std::cout << "MMMeeeooowwww!" << std::endl;
}