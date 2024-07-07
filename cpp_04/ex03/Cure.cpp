#include "Cure.hpp"

Cure::Cure()
{
    this->Type = "cure";
    std::cout << "Cure has been created using default constructor" << std::endl;
}

Cure::Cure(const Cure& other)
{
    std::cout << "Cure has been created using copy constructor" << std::endl;
    this->Type = other.Type;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure is using copy assignment operator" << std::endl;
    this->Type = other.Type;
    return (*this);
}

AMateria* Cure::clone() const
{
    AMateria* materia = new Cure();
    return (materia);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure has been destroyed" << std::endl;
}