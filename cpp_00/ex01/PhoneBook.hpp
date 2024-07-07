#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact arr[8];
	public:
		Contact get_contact(int i);
		void	set_contact(Contact a_contact, int i);
		
};

# endif