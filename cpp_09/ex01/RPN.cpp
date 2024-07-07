#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other)
{
    this->_stack = other._stack;
    return (*this);
}
RPN::~RPN() {}


void    RPN::add_number(long long a)
{
    this->_stack.push(a);
}

long long     RPN::get_top_pop()
{
    long long a = this->_stack.top();
    this->_stack.pop();
    return (a);
}

int     RPN::get_size() const
{
    return (this->_stack.size());
}