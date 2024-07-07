#include "Contact.hpp"

std::string Contact::get_first_name(void)
{
    return (first_name);
}

std::string Contact::get_last_name(void)
{
    return (last_name);
}

std::string Contact::get_nickname(void)
{
    return (nickname);
}

std::string Contact::get_phone_number(void)
{
    return (phone_number);
}

std::string Contact::get_darkest_secret(void)
{
    return (darkest_secret);
}

int Contact::get_index(void)
{
    return (index);
}

Contact::Contact(std::string f_name, std::string l_name, std::string nick_name,
		        std::string ph_number, std::string dark_secret, int idx) : first_name(f_name), last_name(l_name),
                nickname(nick_name), phone_number(ph_number), darkest_secret(dark_secret), index(idx) {}
            
Contact::Contact(void){}