#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

template <typename T>
int easyfind(T& container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
    {
        std::cout << "ths value has been found" << std::endl;
        return (0);
    }
    return (1);
}


#endif