# include "HumanB.hpp"

HumanB::HumanB(std::string h_name) : name(h_name), weapon(nullptr){}

void    HumanB::setWeapon(Weapon &humanWeapon)
{
    weapon = &humanWeapon;
}

void    HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " can not attack, he has no weapon" << std::endl;
}