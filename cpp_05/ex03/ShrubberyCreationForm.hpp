# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string tar_get);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void  execute(Bureaucrat const & executor) const;



        ~ShrubberyCreationForm();

};






#endif