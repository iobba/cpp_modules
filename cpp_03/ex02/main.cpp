#include "FragTrap.hpp"

int main()
{
    FragTrap    a("warior_1");
    FragTrap    c("warior_2");
    FragTrap    b;

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

    
    a.highFivesGuys();
}