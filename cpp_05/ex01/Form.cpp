#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), to_sign(150), to_execute(150) {} 

Form::Form(std::string na_me, int to_si_gn, int to_exe_cute) : name(na_me), to_sign(to_si_gn), to_execute(to_exe_cute)
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
		std::cout << name << " Form has been created" << std::endl;
	}
}

Form::Form(const Form& other) : name(other.name), to_sign(other.to_sign), to_execute(other.to_execute)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= this->get_grade_to_sign())
		this->is_signed = true;
	else
		throw Form::GradeTooLowException();
}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low.";
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::get_is_signed() const
{
	return (this->is_signed);
}

int			Form::get_grade_to_sign() const
{
	return (this->to_sign);
}

int			Form::get_grade_to_exec() const
{
	return (this->to_execute);
}

std::ostream& operator<< (std::ostream& output, const Form & form)
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

Form::~Form() {}


