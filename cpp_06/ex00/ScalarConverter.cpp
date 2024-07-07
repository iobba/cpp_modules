#include "ScalarConverter.hpp"

int     ScalarConverter::int_val = 0;
char    ScalarConverter::char_val = 0;
double  ScalarConverter::double_val = 0;
float   ScalarConverter::float_val = 0;
int		ScalarConverter::type = 0;
std::string ScalarConverter::str = "";

int is_int(std::string input)
{
    unsigned long int j = 0;
    unsigned long int i = 0; // compare with (unsigned long int (length))
    if (input[0] == '-' || input[0] == '+')
    {
        i++;
        j++;
    }
    while(i < input.length())
    {
        if (std::isdigit(input[i]))
            j++;
        i++;
    }
    if (j == i && j > 1)
        return (1);
    return (0);
}

int is_char(std::string input)
{
    if (input.length() == 1 || input.length() == 0)
        return (1);
    return (0);
}

int is_float(std::string input)
{
    unsigned long int i = 0;
    int check = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < input.length() && std::isdigit(input[i]))
    {
        check = 1;
        i++;
    }
    if (i < input.length() && input[i] == '.')
    {
        if (check == 1)
            check++;
        i++;
    }
    while (i < input.length() && std::isdigit(input[i]))
    {
        if (check >= 2)
            check = 3;
        i++;
    }
    if (i < input.length() && input[i] == 'f' && i + 1 == input.length())
        check++;
    if (check == 4)
        return (1);
    return (0);
}

int is_double(std::string input)
{
    unsigned long int i = 0;
    int check = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < input.length() && std::isdigit(input[i]))
    {
        check = 1;
        i++;
    }
    if (i < input.length() && input[i] == '.')
    {
        if (check == 1)
            check++;
        i++;
    }
    while (i < input.length() && std::isdigit(input[i]))
    {
        if (check >= 2)
            check = 3;
        i++;
    }
    if (check == 3 && i == input.length())
        return (1);
    return (0);
}

void ScalarConverter::print_char()
{
    std::cout << "char: ";
    if (type == _inf || int_val < 0) // inf or negative
        std::cout << "impossible";
    else if ((char_val < 32 || char_val > 126)) // is displayable
        std::cout << "Non displayable";
    else
        std::cout << "'" << char_val << "'";
    std::cout << std::endl;
}

void ScalarConverter::print_int()
{
    std::cout << "int: ";
    if (type == _inf)
        std::cout << "impossible";
    else
        std::cout << int_val;
    std::cout << std::endl;
}

void ScalarConverter::print_float()
{
    std::cout << "float: ";
    if (type == _inf)
    {
        if (str == "+inff" || str == "-inff" || str == "nanf")
            std::cout << str;
        else
            std::cout << str << "f";
    }
    else
    {
        std::cout << float_val;
        if (str.find('.') == std::string::npos || float_val == int_val)
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::print_double()
{
    std::cout << "double: ";
    if (type == _inf)
    {
        if (str == "+inff" || str == "-inff" || str == "nanf")
            std::cout << str.substr(0, str.length() - 1);
        else
            std::cout << str;
    }
    else
    {
        std::cout << double_val;
        if (str.find('.') == std::string::npos || double_val == int_val)
            std::cout << ".0";
    }
    std::cout << std::endl;
}

void    ScalarConverter::printing(void)
{
    if (type == _none)
    {
        std::cerr << "the argument should be either an int, char, float, or double type" << std::endl;
        return ;
    }
    print_char();
    print_int();
    print_float();
    print_double();
}

void    ScalarConverter::convert(std::string input)
{
    str = input;
    if (is_int(input))
    {
        type = _int;
        int_val = static_cast<int>(std::stoi(input));
        char_val = static_cast<char>(std::stoi(input));
        float_val = static_cast<float>(std::stoi(input));
        double_val = static_cast<double>(std::stoi(input));
    }
    else if (is_char(input))
    {
        type = _char;
        int_val = static_cast<int>(input[0]);
        char_val = static_cast<char>(input[0]);
        float_val = static_cast<float>(input[0]);
        double_val = static_cast<double>(input[0]);
    }
    else if (is_float(input))
    {
        type = _float;
        int_val = static_cast<int>(std::stof(input));
        char_val = static_cast<char>(std::stof(input));
        float_val = static_cast<float>(std::stof(input));
        double_val = static_cast<double>(std::stof(input));
    }
    else if (is_double(input))
    {
        type = _double;
        int_val = static_cast<int>(std::stod(input));
        char_val = static_cast<char>(std::stod(input));
        float_val = static_cast<float>(std::stod(input));
        double_val = static_cast<double>(std::stod(input));
    }
    else if (input == "+inf" || input == "+inff" || input == "-inf" 
            || input == "-inff" || input == "nan" || input == "nanf")
        type = _inf;
    else
        type = _none;
    printing();
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    int_val = other.int_val;
    char_val = other.char_val;
    float_val = other.float_val;
    double_val = other.double_val;
    type = other.type;
    str = other.str;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}