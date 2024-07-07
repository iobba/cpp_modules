#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class   Serializer
{
    public:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

        ~Serializer();
};



#endif