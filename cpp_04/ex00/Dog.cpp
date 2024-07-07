#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "A Dog has been created using default constructor" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "A Dog has been created using copy constructor" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->type = other.type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "A Dog has been destroyed" << std::endl;
}

void   Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}