# ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class  HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(std::string h_name);
        void    setWeapon(Weapon &humanWeapon);
        void    attack();
};


# endif