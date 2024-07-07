# include "HumanA.hpp"

HumanA::HumanA(std::string h_name, Weapon &a_weapon) : name(h_name), weapon(a_weapon){}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}