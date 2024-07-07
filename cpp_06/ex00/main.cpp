#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "invalid number of arguments" << std::endl;
        return (1);
    }
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch (std::out_of_range t)
    {
        std::cout << "Exeption : " << "argument is out of range" << std::endl;
    }
    catch (...)
    {
        std::cout << "Exeption : " << "something went wrong *_*" << std::endl;
    }
    return (0);
}