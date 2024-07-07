# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
class ICharacter;

class   AMateria
{
    protected:
        std::string Type;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        virtual ~AMateria();
};

# include "ICharacter.hpp"

# endif