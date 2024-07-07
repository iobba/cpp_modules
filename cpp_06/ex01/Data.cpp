#include "Data.hpp"

Data::Data() : value(0) {}

Data::Data(int val) : value(val) {}

Data::Data(const Data& other) : value(other.value) {}

Data& Data::operator=(const Data& other)
{
    this->value = other.value;
    return (*this);
}

void    Data::set_value(int val)
{
    this->value = val;
}

int     Data::get_value()
{
    return (this->value);
}

Data::~Data() {}