#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "A Cat has been created using default constructor" << std::endl;
    this->cat_brain = new Brain();
}

Cat::Cat(const Cat& other)
{
    std::cout << "A Cat has been created using copy constructor" << std::endl;
    this->type = other.type;
    this->cat_brain = new Brain();
    this->cat_brain->operator=(*(other.cat_brain));
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->type = other.type;
    this->cat_brain->operator=(*(other.cat_brain));
    return(*this);
}

Cat::~Cat()
{
    delete cat_brain;
    std::cout << "A Cat has been destroyed" << std::endl;
}

void   Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

std::string Cat::get_idea(int i) const
{
    if (i >= 0 && i < 100)
        return (cat_brain->ideas[i]);
    return ("nothig");
}

void    Cat::set_idea(int i, std::string str)
{
    if (i >= 0 && i < 100)
        this->cat_brain->ideas[i] = str;
}