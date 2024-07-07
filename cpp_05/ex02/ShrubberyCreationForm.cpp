#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tar_get) : AForm("ShrubberyCreationForm", 145, 137), target(tar_get)
{
    std::cout << "A ShrubberyCreationForm with " << target << "(target) has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), 145, 137)
{
    *this = other;
} 


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    this->target = other.target;
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->get_is_signed() == false)
        throw FormNotSignedExeption();
    else if (executor.getGrade() <= this->get_grade_to_exec())
    {
        std::ofstream outfile(target + "_shrubbery");
        if (!outfile)
        {
            std::cerr << "ERROR : creating a file named : " <<  target + "_shrubbery" << std::endl;
            exit(1);
        }
        outfile << "           --------         \n"
                << "         //%&%*&*\\\\       \n"
                << "        //$*&^(*()\\\\      \n"
                << "       //76jwdjbh87\\\\     \n"
                << "      //*&gv5659)[],\\\\    \n"
                << "     //89jhbjvt$#%^$*\\\\   \n"
                << "    //#####***#####88#\\\\  \n"
                << "   ##-------------------##  \n"
                << "             | |            \n"
                << "             | |            \n"
                << "             | |            \n"
                << "             | |            \n"
                << "             | |            \n"
                << "             | |            \n"
                << "       ###############        ";
        outfile.close();
    }
    else
        throw GradeTooLowException();
}


ShrubberyCreationForm::~ShrubberyCreationForm() {}
