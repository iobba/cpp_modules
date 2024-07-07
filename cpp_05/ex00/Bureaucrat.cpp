#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "a Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : name(Name)
{
    if (Grade >= 1 && Grade <= 150)
    {
        std::cout << Name << " Bureaucrat has been creating" << std::endl;
        this->grade = Grade;
    }
    else if (Grade < 1)
    {
        throw GradeTooHighException();
    }
    else
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::increment_grade()
{
    if (this->grade > 1)
    {
        std::cout << "the grade of " << this->name << " has been incremented" << std::endl;
        grade -= 1;
    }
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrement_grade()
{
    if (this->grade < 150)
    {
        std::cout << "the grade of " << this->name << " has been decremented" << std::endl;
        grade += 1;
    }
    else
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low.";
}

std::ostream& operator<<(std::ostream& outout_stream, const Bureaucrat& bureaucrat)
{
    outout_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "."<< std::endl;
    return (outout_stream);
}

Bureaucrat::~Bureaucrat() {}