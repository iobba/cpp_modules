#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "A Cat has been created using default constructor" << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "A Cat has been created using copy constructor" << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->type = other.type;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "A Cat has been destroyed" << std::endl;
}

void   Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}