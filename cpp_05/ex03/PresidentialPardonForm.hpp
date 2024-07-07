# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string tar_get);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void  execute(Bureaucrat const & executor) const;



        ~PresidentialPardonForm();

};






#endif