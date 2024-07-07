#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap    a("warior_1");
    DiamondTrap    c("warior_2");
    DiamondTrap    b;

    b = c;

    a.attack("warior_3");
    b.attack("warior_3");
    a.takeDamage(4);
    b.takeDamage(144);
    a.beRepaired(2);
    a.attack("warior_3");
    b.attack("warior_3");
    a.takeDamage(4);
    a.takeDamage(4);
    a.beRepaired(3);
    b.beRepaired(30);

    
    a.whoAmI();
}