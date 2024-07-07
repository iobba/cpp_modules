#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
        replace(av[1], av[2], av[3]);
    else
        std::cerr << "invalid number of arguments" << std::endl;
    return 0;
}