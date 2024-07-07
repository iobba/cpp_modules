# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria*   slot[4];
    
    public:
        Character();
        Character(const std::string na_me);
        Character(const Character& other);
        Character& operator=(const Character& other);

        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        ~Character();
        AMateria** infinite_Arr;
        void    add_materia(AMateria* m);
};












#endif