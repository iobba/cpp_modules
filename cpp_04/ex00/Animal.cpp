#include "Animal.hpp"

Animal::Animal() : type("an_animal")
{
    std::cout << "An animal has been created using default constructor" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "An animal has been created using copy constructor" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    this->type = other.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "An Animal has been destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void   Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}