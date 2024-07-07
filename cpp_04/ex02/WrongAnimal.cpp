#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong_animal")
{
    std::cout << "A wrong animal has been created using default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "A wrong animal has been created using copy constructor" << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "wrong Animal Copy assignment operator called" << std::endl;
    this->type = other.type;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "A wrong Animal has been destroyed" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void   WrongAnimal::makeSound() const
{
    std::cout << "wrong Animal sound" << std::endl;
}