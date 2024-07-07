#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "-------------------use of virtual----------------------------------\n\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();


    std::cout << "\n-------------------no virtual----------------------------------\n\n";
    WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* catWrong = new WrongCat();

	std::cout << metaWrong->getType() << std::endl;
	std::cout << catWrong->getType() << std::endl;
	metaWrong->makeSound();
	catWrong->makeSound();

    std::cout << "\n---------------------assignment--------------------------------\n\n";
    WrongAnimal     wrong;

    *metaWrong = wrong;

    metaWrong->makeSound();

    std::cout << "\n----------------------animal sound-------------------------------\n\n";
    Animal  animal;
    animal.makeSound();

    std::cout << "\n----------------------WrongCat sound-------------------------------\n\n";
    WrongCat    a_cat;

    a_cat.makeSound();

    std::cout << "\n----------------------time to destroy-------------------------------\n\n";
    delete meta;
    delete j;
    delete i;

	delete metaWrong;
	delete catWrong;


    return (0);
}