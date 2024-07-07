#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

void tests(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    
////////////////////////////
    IMateriaSource* vov = new MateriaSource();
    vov->learnMateria(new Ice());
    vov->learnMateria(new Cure());
    vov->learnMateria(new Ice());
    vov->learnMateria(new Ice());
    vov->learnMateria(new Cure());
    
    ICharacter* moi = new Character("moi");
    
    AMateria* tmp1 = NULL;
    AMateria* tmp2 = NULL;
    tmp1 = vov->createMateria("ice");
    moi->equip(tmp1);
    std::cout << "[+] ICE = " << tmp1->getType() << std::endl;
    
    tmp2 = vov->createMateria("cure");
    moi->equip(tmp2);
    std::cout << "[+] CURE = " << tmp2->getType() << std::endl;
    
    ICharacter* boby = new Character("boby");
    
    moi->use(0, *boby);
    moi->use(1, *boby);
    std::cout << "[+] " << tmp1->getType() << std::endl;
    std::cout << "[+] " << tmp2->getType() << std::endl;

    
    moi->use(0, *boby);
    std::cout << "[+] " << tmp1->getType() << std::endl;
    std::cout << "[+] " << tmp2->getType() << std::endl;

    moi->unequip(0);
    moi->unequip(1);
    moi->unequip(2);// over

    delete boby;
    delete vov;
    delete moi;

    delete bob;
    delete me;
    delete src;
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    
////////////////////////////
    IMateriaSource* vov = new MateriaSource();
    vov->learnMateria(new Ice());
    vov->learnMateria(new Cure());
    vov->learnMateria(new Ice());
    vov->learnMateria(new Ice());
    vov->learnMateria(new Cure());
    
    ICharacter* moi = new Character("moi");
    
    AMateria* tmp1 = NULL;
    AMateria* tmp2 = NULL;
    tmp1 = vov->createMateria("ice");
    moi->equip(tmp1);
    std::cout << "[+] ICE = " << tmp1->getType() << std::endl;
    
    tmp2 = vov->createMateria("cure");
    moi->equip(tmp2);
    std::cout << "[+] CURE = " << tmp2->getType() << std::endl;
    
    ICharacter* boby = new Character("boby");
    
    moi->use(0, *boby);
    moi->use(1, *boby);
    std::cout << "[+] " << tmp1->getType() << std::endl;
    std::cout << "[+] " << tmp2->getType() << std::endl;

    
    moi->use(0, *boby);
    std::cout << "[+] " << tmp1->getType() << std::endl;
    std::cout << "[+] " << tmp2->getType() << std::endl;

    moi->unequip(0);
    moi->unequip(1);
    moi->unequip(2);// over

    delete boby;
    delete vov;
    delete moi;

    delete bob;
    delete me;
    delete src;  

    return (0);
}