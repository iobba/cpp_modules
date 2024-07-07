#include <iostream>

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        std::string str = av[i];
        for (int j = 0; str[j]; j++)
            std::cout << (char)toupper(str[j]);
        i++;
    }
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}