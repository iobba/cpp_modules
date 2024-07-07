#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra salmon for my 7XL-burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: If you put enough salmon in my burger!, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra salmon for free." << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std:: endl;
}

void Harl::complain(std::string level)
{
    int i = 0;
    std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*ptr[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    while (i < 4)
    {
        if (arr[i] == level)
        {
            (this->*ptr[i])();
            break;
        }
        i++;
    }
}