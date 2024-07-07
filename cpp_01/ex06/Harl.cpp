#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra salmon for my 7XL-burger. I really do!" << std::endl << std:: endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "If you put enough salmon in my burger!, I wouldn't be asking for more!" << std::endl << std:: endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra salmon for free." << std::endl << std:: endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std:: endl << std:: endl;
}

void Harl::complain(std::string level)
{
    int i = 0;
    std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4)
    {
        if (arr[i] == level)
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            Harl::debug();
        case 1:
            Harl::info();
        case 2:
            Harl::warning();
        case 3:
            Harl::error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}