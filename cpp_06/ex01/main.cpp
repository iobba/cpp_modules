#include "Serializer.hpp"

int main()
{
    Data data1(10);

    uintptr_t ptr1 = Serializer::serialize(&data1);
    // std::cout << "the memory address of data1 is " << (uintptr_t)&data1 << std::endl;
    // std::cout << "the value of ptr1 is " << ptr1 << std::endl;
    Data* data2_ptr = Serializer::deserialize(ptr1);
    if (data2_ptr->get_value() == data1.get_value())
        std::cout << "Serialization done successfully" << std::endl;
    else
        std::cout << "Serialization failed" << std::endl;
    
    // another test

    Data data3(100);
    if (Serializer::deserialize(Serializer::serialize(&data3)) == &data3)
        std::cout << "Serialization done successfully" << std::endl;
    else
        std::cout << "Serialization failed" << std::endl;
}