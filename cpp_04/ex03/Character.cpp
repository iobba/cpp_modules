#include "Character.hpp"

void    Character::add_materia(AMateria* m)
{
    int i = 0, j = 0;
    while(infinite_Arr != NULL && infinite_Arr[i++])
        j++;
    AMateria** another_Arr = new AMateria*[j + 2];
    i = 0;
    while (infinite_Arr && infinite_Arr[i])
    {
        another_Arr[i] = infinite_Arr[i];
        i++;
    }
    another_Arr[i] = m;
    another_Arr[++i] = NULL;
    delete[] infinite_Arr;
    infinite_Arr = another_Arr;
}

Character::Character() : name("default")
{
    for(int i = 0; i < 4; i++)
        slot[i] = nullptr;
    AMateria** infinite_Arr = new AMateria*[1];
    infinite_Arr[0] = NULL;
    std::cout << "Character has been created using default consrtuctor" << std::endl;
}

Character::Character(const std::string na_me) : name(na_me)
{
    for(int i = 0; i < 4; i++)
        slot[i] = nullptr;
    std::cout << "Character has been created using a consrtuctor" << std::endl;
}

Character::Character(const Character& other)
{
    std::cout << "Character has been created using copy constructor" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Character  copy assignment operator" << std::endl;
    this->name = other.name;
    for(int i = 0; i < 4; i++)
    {
        if (this->slot[i])
            delete slot[i];
        if (other.slot[i] == nullptr)
            this->slot[i] = nullptr;
        else
            this->slot[i] = other.slot[i]->clone();
    }
    return (*this);
}

std::string const& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while (i < 4)
    {
        if (slot[i] == nullptr)
        {
            this->slot[i] = m;
            return ;
        }
        i++;
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (this->slot[idx])
            add_materia(this->slot[idx]);
        this->slot[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
        slot[idx]->use(target);
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        if (slot[i])
            delete slot[i];
    int i = 0;
    while(infinite_Arr && infinite_Arr[i])
    {
        delete infinite_Arr[i];
        i++;
    }
    delete[] infinite_Arr;
    std::cout << "Character has been destroyed" << std::endl;
}