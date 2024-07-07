#include "AMateria.hpp"

AMateria::AMateria() : Type("default")
{
    std::cout << "An AMateria has been created using default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : Type(type)
{
    std::cout << Type << " AMateria has been created using a constructor" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << other.Type << " AMateria has been created using copy constructor" << std::endl;
    this->Type = other.Type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << other.Type << " AMateria is using copy assignment operator" << std::endl;
    this->Type = other.Type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->Type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "this is just a materia, nothing to be done for " <<  target.getName() << std::endl;
}

AMateria::~AMateria()
{
    std::cout << Type << " AMateria has been destroyed" << std::endl;
}