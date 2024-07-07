# ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class  HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        void    attack();
        HumanA(std::string h_name, Weapon &a_weapon);
};


# endif