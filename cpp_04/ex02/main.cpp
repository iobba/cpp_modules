#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    ///////////// making sure that Animal class is now an abstract class, she needs an implementation for its pure virtual method 'makeSound'

    //Animal      animal;


    const int size = 4;
    const Animal* arr[size];
    std::cout << "\n----------------Creating animals-------------------------------\n\n";
    int i = 0;
    while(i < size)
    {
        if (i < size / 2)
            arr[i] = new Dog();
        else
            arr[i] = new Cat();
        i++;
    }
    std::cout << "\n----------------Let's listen to their sounds-------------------\n\n";
    i = 0;
    while (i < size)
    {
        std::cout << arr[i]->getType() << " ---> ";
        arr[i]->makeSound();
        i++;
    }

    //////////////////////////// some tests on the Brain of our Dogs and Cats !!!

    // std::cout << "\n----------------Create cats and dogs--------------------------------\n\n";
    // Dog     dog1;
    // Cat     cat1;

    // // fill their brains
    // i = 0;
    // while(i < 100)
    // {
    //     dog1.set_idea(i, "dog1 idea number : " + std::to_string(i + 1));
    //     cat1.set_idea(i, "cat1 idea number : " + std::to_string(i + 1));
    //     i++;
    // }

    // std::cout << "\n----------------Discover dog1 brain------------------------------\n\n";
    // for(i = 0; i < 100; i++)
    //     std::cout << dog1.get_idea(i) << std::endl;

    // std::cout << "\n----------Create dog2 using copy assignment operator------------\n\n";
    // Dog     dog2;
    // dog2 = dog1;
    // std::cout << "\n----------------Discover dog2 brain------------------------------\n\n";
    // for(i = 0; i < 100; i++)
    //     std::cout << dog2.get_idea(i) << std::endl;


    // std::cout << "\n--------------------Discover cat1 brain-------------------------\n\n";
    // for(i = 0; i < 100; i++)
    //     std::cout << cat1.get_idea(i) << std::endl;

    // std::cout << "\n------------Create cat2 using copy constructor-------------------\n\n";
    // Cat     cat2(cat1);
    // std::cout << "\n----------------Discover cat2 brain------------------------------\n\n";
    // for(i = 0; i < 100; i++)
    //     std::cout << cat2.get_idea(i) << std::endl;

    std::cout << "\n----------------Time to destroy--------------------------------\n\n";
    i = 0;
    while (i < size)
    {
        delete arr[i];
        i++;
    }

    return (0);
}