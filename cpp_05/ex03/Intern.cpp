#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

AForm* Intern::makeForm(std::string name, std::string ta_rg_et)
{
    std::string names_arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*      Forms_arr[3] = {new ShrubberyCreationForm(ta_rg_et), new RobotomyRequestForm(ta_rg_et)
                                , new PresidentialPardonForm(ta_rg_et)};
    for(int i = 0; i < 3; i++)
    {
        if (names_arr[i] == name)
        {
            std::cout << "Intern creates " << name << " form." << std::endl;
            return (Forms_arr[i]);
        }
    }
    std::cout << "Intern couldn't create " << name << " form." << std::endl;
    return (nullptr);
}

Intern::~Intern() {}