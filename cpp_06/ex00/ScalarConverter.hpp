# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#define _int	1
#define _char	2
#define _float	3
#define _double	4
#define _none	5
#define _inf	6


class   ScalarConverter
{
	private:
		static int     int_val;
		static char    char_val;
		static float   float_val;
		static double  double_val;
		static int		type;
		static std::string str;
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert (std::string input);
		static void printing();
		static void print_char();
		static void print_int();
		static void print_float();
		static void print_double();
};

#endif