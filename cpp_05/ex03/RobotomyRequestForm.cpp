#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string tar_get) : AForm("robotomy request", 72, 45), target(tar_get) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), 72, 45)
{
    *this = other;
} 

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->get_is_signed() == false)
        throw FormNotSignedExeption();
    else if (executor.getGrade() <= this->get_grade_to_exec())
    {
        static int check;
        if (check % 2 == 0)
            std::cout << target << " got lucky, and it has been robotomized\n";
        else
            std::cout << "unfortunately " << target << " robotomy failed.\n";
        check++;
    }
    else
        throw GradeTooLowException();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}