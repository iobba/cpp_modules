#include  "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        store[i] = nullptr;
    std::cout << "MateriaSource has been created using default consrtuctor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource has been created using copy constructor" << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource  copy assignment operator" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if (this->store[i])
            delete store[i];
        if (other.store[i] == nullptr)
            this->store[i] = nullptr;
        else
            this->store[i] = other.store[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    while (i < 4)
    {
        if (store[i] == nullptr)
        {
            this->store[i] = m;
            return ;
        }
        i++;
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < 4)
    {
        if (store[i] && store[i]->getType() == type)
            return (store[i]->clone());
        i++;
    }
    return (NULL);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        if (store[i])
            delete store[i];
    std::cout << "MateriaSource has been destroyed" << std::endl;
}