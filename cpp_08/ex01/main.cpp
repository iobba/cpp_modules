#include "Span.hpp"


int main()
{
    Span    sp1(5);

    std::cout << "--------------- sp1 ----------------\n";
    try
    {
        sp1.addNumber(5);
        sp1.addNumber(20);
        sp1.addNumber(59);
        sp1.addNumber(40);
        sp1.addNumber(57);
        sp1.write_arr_elems();
        std::cout << "shortest_distance is : " << sp1.shortestSpan() << std::endl;
        std::cout << "longest_distance is : " << sp1.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span    sp2(10);

    std::cout << "\n--------------- sp2 ----------------\n";
    try
    {
        sp2.addNumber(-1);
        sp2.addNumber(-13);
        sp2.addNumber(2147483647);
        std::cout << "shortest_distance is : " << sp2.shortestSpan() << std::endl;
        std::cout << "longest_distance is : " << sp2.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------before add-range()----------\n";
    sp2.write_arr_elems();

    int num_arr[5] = {1, 2, 3, 4, 5};
    std::vector<int>  vec(num_arr, num_arr + 5);
    try
    {
        sp2.add_range(vec.begin(), vec.end());
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------after add-range()----------\n";
    sp2.write_arr_elems();

    // std::cout << "\n--------------10 000 numbers---------\n\n";
    // Span    sp3(10000);
    // try
    // {
    //     for (int i = 0; i < 10000; i++)
    //     {
    //         if (i % 3 == 0)
    //             sp3.addNumber(i + 17);
    //         else if (i % 7 == 0)
    //             sp3.addNumber(i + 13);
    //         else
    //             sp3.addNumber(i + 19);
    //     }
    // }
    // catch(std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // sp3.write_arr_elems();
    // std::cout << "shortest_distance is : " << sp3.shortestSpan() << std::endl;
    // std::cout << "longest_distance is : " << sp3.longestSpan() << std::endl;
}