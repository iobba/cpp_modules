#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
    private:
        Brain   *dog_brain;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        void    makeSound() const;

        std::string get_idea(int i) const;
        void        set_idea(int i, std::string str);

        ~Dog();
};




# endif