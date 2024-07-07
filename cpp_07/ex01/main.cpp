#include "iter.hpp"



int main( void )
{
    int int_arr[5] = {1, 2, 3, 4, 5};
    char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    std::string string_arr[5] = {"AA", "BB", "CC", "DD", "EE"};

    // int
    ::iter(int_arr, 5, &fun);
    std::cout << std::endl;

    // char
    ::iter(char_arr, 5, &fun);
    std::cout << std::endl;

    // string
    ::iter(string_arr, 5, &fun);

    return (0);
}