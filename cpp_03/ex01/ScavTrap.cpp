#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap()
{
    std::cout << "a ScavTrap has been created" << std::endl;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
}

ScavTrap::~ScavTrap ()
{
    std::cout << "ScavTrap " << Name << " has been Destroyed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " has been created" << std::endl;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout  << "ScavTrap " << other.Name << " has been created" << " using Copy constructor" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap " << other.Name << " Copy assignment operator called" << std::endl;
    Name = other.Name;
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << " causing "
           << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
    {
        std::cout << "ScavTrap " << Name << " can't attack, he has no hit points or no energy points left!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gatekeeper mode." << std::endl;
}