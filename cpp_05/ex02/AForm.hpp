#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
class Bureaucrat;
#include <fstream>

class   AForm
{
	private:
		std::string const   name;
		bool				is_signed;
		int const			to_sign;
		int const			to_execute;
		AForm();

	public:
		AForm(std::string na_me, int to_si_gn, int to_exe_cute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
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

		class FormNotSignedExeption : public std::exception
        {
            public:
                const char* what() const throw();
        };
		std::string	getName() const;
		bool		get_is_signed() const;
		int			get_grade_to_sign() const;
		int			get_grade_to_exec() const;

		void	beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0; // abstract class
		~AForm();
};

#include "Bureaucrat.hpp"

std::ostream& operator<< (std::ostream& output, const AForm & form);


#endif