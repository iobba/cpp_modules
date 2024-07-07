#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "A Dog has been created using default constructor" << std::endl;
    this->dog_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
    std::cout << "A Dog has been created using copy constructor" << std::endl;
    this->type = other.type;
    this->dog_brain = new Brain();
    this->dog_brain->operator=(*(other.dog_brain));
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->type = other.type;
    this->dog_brain->operator=(*(other.dog_brain));
    return(*this);
}

Dog::~Dog()
{
    delete dog_brain;
    std::cout << "A Dog has been destroyed" << std::endl;
}

void   Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

std::string Dog::get_idea(int i) const
{
    if (i >= 0 && i < 100)
        return (dog_brain->ideas[i]);
    return ("nothig");
}

void    Dog::set_idea(int i, std::string str)
{
    if (i >= 0 && i < 100)
        this->dog_brain->ideas[i] = str;
}