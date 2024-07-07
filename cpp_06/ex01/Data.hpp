#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class   Data
{
    private:
        int value;

    public:
        Data();
        Data(int val);
        Data(const Data& other);
        Data& operator=(const Data& other);

        void    set_value(int val);
        int     get_value();

        ~Data();
};



#endif
