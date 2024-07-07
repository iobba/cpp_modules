#include "Ice.hpp"

Ice::Ice()
{
    this->Type = "ice";
    std::cout << "Ice has been created using default constructor" << std::endl;
}

Ice::Ice(const Ice& other)
{
    std::cout << "Ice has been created using copy constructor" << std::endl;
    this->Type = other.Type;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice is using copy assignment operator" << std::endl;
    this->Type = other.Type;
    return (*this);
}

AMateria* Ice::clone() const
{
    AMateria* materia = new Ice();
    return (materia);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice has been destroyed" << std::endl;
}