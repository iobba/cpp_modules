#include "RPN.hpp"

int     is_valid_arg(std::string arg)
{
    int digits_num = 0;
    int operator_num = 0;
    if (arg.length() == 0 || arg.length() == 1 || arg.length() == 2)
        return (0);
    for(size_t i = 0; i < arg.length(); i++)
    {
        if (std::isdigit(arg[i]))
            digits_num++;
        else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '/' || arg[i] == '*')
            operator_num++;
        else if (arg[i] != ' ')
            return (0);
    }
    if (digits_num == operator_num + 1)
        return (1);
    return (0);
}

long long   _result_(char _operator, long long num1, long long num2)
{
    if (_operator == '+')
        return(num1 + num2);
    else if (_operator == '-')
        return(num1 - num2);
    else if (_operator == '*')
        return(num1 * num2);
    else if (_operator == '/' && num2)
        return(num1 / num2);
    else
    {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
        exit(1);
    }
}

int    calculate_opearations(std::string arg)
{
    RPN     _rpn;
    long long     num1;
    long long     num2;
    for(size_t i = 0; i < arg.length(); i++)
    {
        if (std::isdigit(arg[i]))
            _rpn.add_number(arg[i] - 48);
        else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '/' || arg[i] == '*')
        {
            if (_rpn.get_size() < 2)
                return (1);
            else
            {
                num2 = _rpn.get_top_pop();
                num1 = _rpn.get_top_pop();
                _rpn.add_number(_result_(arg[i], num1, num2));
            }
        }
    }
    std::cout << _rpn.get_top_pop() << std::endl;
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "unvalid number of arguments\nUsage: ./RPN \"number number operator...\"" << std::endl;
        return (1);
    }
    std::string arg = av[1];
    if(is_valid_arg(arg) && !calculate_opearations(arg))
        return (0);
    std::cout << "Error" << std::endl;
    return (1);
}