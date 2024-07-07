#include "Weapon.hpp"

Weapon::Weapon(std::string w_type)
{
    type = w_type;
}

const std::string& Weapon::getType()
{
    return (type);
}

void    Weapon::setType(std::string new_type)
{
    type = new_type;
}