#include "PhoneBook.hpp"

Contact PhoneBook::get_contact(int i)
{
	return (arr[i]);
}

void	PhoneBook::set_contact(Contact a_contact, int i)
{
	arr[i] = a_contact;
}