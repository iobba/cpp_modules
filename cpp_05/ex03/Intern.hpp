#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class   Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        AForm* makeForm(std::string name, std::string ta_rg_et);
        
        ~Intern();

};








#endif