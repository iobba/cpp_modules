#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap ()
{
    std::cout << "a DiamondTrap has been created" << std::endl;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const std::string name)
{
    std::cout << "DiamondTrap " << name << " has been created" << std::endl;
    Name = name;
    ClapTrap::Name = name + "_clap_name";
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout  << "DiamondTrap " << other.Name << " has been created" << " using Copy constructor" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap " << other.Name << " Copy assignment operator called" << std::endl;
    Name = other.Name;
    ClapTrap::Name = other.Name + "_clap_name";
    Hit_points = other.Hit_points;
    Energy_points = other.Energy_points;
    Attack_damage = other.Attack_damage;
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "my name is " << Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}

DiamondTrap::~DiamondTrap ()
{
    std::cout << "DiamondTrap " << Name << " has been Destroyed" << std::endl;
}