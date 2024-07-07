#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private:
        Brain   *cat_brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        void    makeSound() const;

        std::string get_idea(int i) const;
        void        set_idea(int i, std::string str);

        ~Cat();
};




# endif