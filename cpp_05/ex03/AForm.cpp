#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), to_sign(150), to_execute(150) {}  

AForm::AForm(std::string na_me, int to_si_gn, int to_exe_cute) : name(na_me), to_sign(to_si_gn), to_execute(to_exe_cute)
{
	if (to_si_gn < 1 || to_exe_cute < 1)
    {
        throw GradeTooHighException();
    }
    else if (to_si_gn > 150 || to_exe_cute > 150)
    {
        throw GradeTooLowException();
    }
	else
	{
		this->is_signed = false;
	}
}

AForm::AForm(const AForm& other) : name(other.name), to_sign(other.to_sign), to_execute(other.to_execute)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->get_grade_to_sign())
		this->is_signed = true;
	else
		throw AForm::GradeTooLowException();
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low.";
}

const char* AForm::FormNotSignedExeption::what() const throw()
{
    return "AForm not signed.";
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool		AForm::get_is_signed() const
{
	return (this->is_signed);
}

int			AForm::get_grade_to_sign() const
{
	return (this->to_sign);
}

int			AForm::get_grade_to_exec() const
{
	return (this->to_execute);
}

std::ostream& operator<< (std::ostream& output, const AForm & form)
{
	output << form.getName() << " is ";
	if (form.get_is_signed())
		output << "a signed Form";
	else
		output << "an unsigned Form";
	output << ", its required grade to be signed is " << form.get_grade_to_sign();
	output << " and its required grade to be executed is " << form.get_grade_to_exec() << ".\n";
	return (output);
}


AForm::~AForm() {}

