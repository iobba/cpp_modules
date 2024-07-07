#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "A Brain has been created using default constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "A Brain has been created using copy constructor" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = other.ideas[i];
        i++;
    }
    return(*this);
}

Brain::~Brain()
{
    std::cout << "A Brain has been destroyed" << std::endl;
}
