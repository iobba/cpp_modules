# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        std::string const   name;
        int                 grade;
        Bureaucrat();

    public:
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

        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string getName() const;
        int getGrade() const;

        void    increment_grade();
        void    decrement_grade();

        void    signForm(AForm& form) const;
        void    executeForm(AForm const & form);
        ~Bureaucrat();


};

std::ostream& operator<<(std::ostream& outout_stream, const Bureaucrat& bureaucrat);


#endif