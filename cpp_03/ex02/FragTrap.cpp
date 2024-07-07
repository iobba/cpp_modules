#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap()
{
    std::cout << "a FragTrap has been created" << std::endl;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
}

FragTrap::~FragTrap ()
{
    std::cout << "FragTrap " << Name << " has been Destroyed" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " has been created" << std::endl;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout  << "FragTrap " << other.Name << " has been created" << " using Copy constructor" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap " << other.Name << " Copy assignment operator called" << std::endl;
    Name = other.Name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "FragTrap " << Name << " attacks " << target << " causing "
           << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
    {
        std::cout << "FragTrap " << Name << " can't attack, he has no hit points or no energy points left!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "Give me a high five!" << std::endl;
}