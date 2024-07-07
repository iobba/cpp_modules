#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string tar_get) : AForm("presidential pardon", 25, 5), target(tar_get) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), 25, 5)
{
    *this = other;
} 

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->get_is_signed() == false)
        throw FormNotSignedExeption();
    else if (executor.getGrade() <= this->get_grade_to_exec())
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
    }
    else
        throw GradeTooLowException();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    this->target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}