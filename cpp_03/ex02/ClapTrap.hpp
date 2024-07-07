# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap
{
    protected:
        std::string Name;
        unsigned int Hit_points;
        unsigned int Energy_points;
        unsigned int Attack_damage;

    public:
        ClapTrap ();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ClapTrap(const std::string name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ~ClapTrap ();


};





# endif