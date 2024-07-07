#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class   Form
{
	private:
		std::string const   name;
		bool				is_signed;
		int const			to_sign;
		int const			to_execute;
		Form();

	public:
		Form(std::string na_me, int to_si_gn, int to_exe_cute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

		std::string	getName() const;
		bool		get_is_signed() const;
		int			get_grade_to_sign() const;
		int			get_grade_to_exec() const;

		void	beSigned(Bureaucrat& b);
		~Form();
};

#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& output, const Form & form);


#endif