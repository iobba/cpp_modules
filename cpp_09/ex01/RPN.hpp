#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class   RPN
{
    private:
        std::stack<long long> _stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void        add_number(long long a);
        long long   get_top_pop();
        int         get_size() const;

};


#endif