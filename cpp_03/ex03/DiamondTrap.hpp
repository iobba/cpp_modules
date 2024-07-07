# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap ();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);

        void attack(const std::string& target);
        void whoAmI();

        ~DiamondTrap ();

};







#endif