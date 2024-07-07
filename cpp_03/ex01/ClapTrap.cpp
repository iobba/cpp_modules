#include "ClapTrap.hpp"

ClapTrap::ClapTrap () : Name("default"), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "a ClapTrap has been created" << std::endl;
}

ClapTrap::~ClapTrap ()
{
    std::cout << "ClapTrap " << Name << " has been Destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap " << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap " << "Copy assignment operator called" << std::endl;
    Name = other.Name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

ClapTrap::ClapTrap(const std::string name) : Name(name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << " causing "
           << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't attack, he has no hit points or no energy points left!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
        if (amount > Hit_points)
            Hit_points = 0;
        else
            Hit_points -= amount;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is already dead and can't take any more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ClapTrap " << Name << " repaires " << amount << " of Hit points!" << std::endl;
        Hit_points += amount;
        Energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is already dead and can't repaire himself!" << std::endl;
    }
}
