#include "Array.hpp"

int main()
{
    Array<int>              a1(3);

    a1[0] = 1111;
    a1[1] = 2222;
    a1[2] = 3333;
    std::cout << "-------------array a1-------\n";
    std::cout << "a1.arr[0] = " << a1[0] << std::endl;
    std::cout << "a1.arr[1] = " << a1[1] << std::endl;
    std::cout << "a1.arr[2] = " << a1[2] << std::endl;
    std::cout << "a1.size   = " << a1.size() << std::endl;

    std::cout << "\n-------------array a2-------\n";
    Array<int>              a2;
    a2 = a1;
    std::cout << "a2.arr[0] = " << a2[0] << std::endl;
    std::cout << "a2.arr[1] = " << a2[1] << std::endl;
    std::cout << "a2.arr[2] = " << a2[2] << std::endl;
    std::cout << "a2.size   = " << a2.size() << std::endl;
    

    Array<std::string>              a3(3);

    a3[0] = "aaaa";
    a3[1] = "bbbb";
    a3[2] = "cccc";
    std::cout << "\n-------------array a3-------\n";
    std::cout << "a3.arr[0] = " << a3[0] << std::endl;
    std::cout << "a3.arr[1] = " << a3[1] << std::endl;
    std::cout << "a3.arr[2] = " << a3[2] << std::endl;
    std::cout << "a3.size   = " << a3.size() << std::endl;

    std::cout << "\n-------------array a4-------\n";
    Array<std::string>              a4(a3);
    std::cout << "a4.arr[0] = " << a4[0] << std::endl;
    std::cout << "a4.arr[1] = " << a4[1] << std::endl;
    std::cout << "a4.arr[2] = " << a4[2] << std::endl;
    std::cout << "a4.size   = " << a4.size() << std::endl;
    
    // out of range
    try{
        std::cout << "a4.arr[10] = " << a4[10] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}