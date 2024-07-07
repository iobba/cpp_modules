#include "easyfind.hpp"


int main()
{
    int numbers1[] = {1, 2, 3, 4, 5};
    int numbers2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v1(numbers1, numbers1 + 5);
    std::list<int> l1(numbers2, numbers2 + 9);
    std::array<int, 15> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int to_find = 5;


    if (::easyfind(v1, to_find))
        std::cout << "ths value not found" << std::endl;
    std::cout << "-----------------------------\n";
    if (::easyfind(l1, to_find))
        std::cout << "ths value not found" << std::endl;
    std::cout << "-----------------------------\n";
    if (::easyfind(a1, to_find))
        std::cout << "ths value not found" << std::endl;
}