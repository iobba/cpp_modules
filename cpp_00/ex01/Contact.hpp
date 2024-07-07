#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <string>
# include <iostream>

class Contact
{
        private:
        	std::string	first_name;
        	std::string	last_name;
        	std::string	nickname;
        	std::string phone_number;
        	std::string	darkest_secret;
        	int			index;

        public:
                Contact(std::string f_name, std::string	l_name, std::string nick_name,
                	        std::string ph_number, std::string dark_secret, int idx);
                Contact(void);
                std::string get_first_name(void);
                std::string get_last_name(void);
                std::string get_nickname(void);
                std::string get_phone_number(void);
                std::string get_darkest_secret(void);
                int         get_index(void);
};

#endif