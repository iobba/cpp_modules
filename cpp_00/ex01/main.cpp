#include "PhoneBook.hpp"

void    Print_One_Field(std::string field)
{
	if (field.length() > 10)
	{
		std::cout << std::setw(9);         
		std::cout << field.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10); 
		std::cout << field;
	}
}

int	not_empty(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	Add_contacts(int num_contacts, PhoneBook *phone_book)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string phone_number;
	std::string	darkest_secret;
	int			index;

	while (1)
	{
		std::cout << "enter first name : ";
		std::getline (std::cin, first_name);
		if (std::cin.eof())
		{
			std::cerr << "eof has been reached\n";
			exit(1);
		}
		if (not_empty(first_name))
			break ;
		else
			std::cout << "shouldn't be an empty field" << std::endl;
	}
	while (1)
	{
		std::cout << "enter last name : ";
		std::getline (std::cin, last_name);
		if (std::cin.eof())
		{
			std::cerr << "eof has been reached\n";
			exit(1);
		}
		if (not_empty(last_name))
			break ;
		else
			std::cout << "shouldn't be an empty field" << std::endl;
	}
	while (1)
	{
		std::cout << "enter nickname : ";
		std::getline (std::cin, nickname);
		if (std::cin.eof())
		{
			std::cerr << "eof has been reached\n";
			exit(1);
		}
		if (not_empty(nickname))
			break ;
		else
			std::cout << "shouldn't be an empty field" << std::endl;
	}
	while (1)
	{
		std::cout << "enter phone number : ";
		std::getline (std::cin, phone_number);
		if (std::cin.eof())
		{
			std::cerr << "eof has been reached\n";
			exit(1);
		}
		if (not_empty(phone_number))
			break ;
		else
			std::cout << "shouldn't be an empty field" << std::endl;
	}
	while (1)
	{
		std::cout << "enter a darkest secret : ";
		std::getline (std::cin, darkest_secret);
		if (std::cin.eof())
		{
			std::cerr << "eof has been reached\n";
			exit(1);
		}
		if (not_empty(darkest_secret))
			break ;
		else
			std::cout << "shouldn't be an empty field" << std::endl;
	}
	if (num_contacts >= 7)
	{
		Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret, 0);
		phone_book->set_contact(new_contact, 0);
	}
	else
	{
		num_contacts++;
		Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret, num_contacts);
		phone_book->set_contact(new_contact, num_contacts);
	}
	return (num_contacts);
}

int	is_number(std::string str)
{
	int i = 0;
	const char *data = str.data();
	if (str.length() == 0)
		return (0);
	while (i < str.length())
	{
		if (data[i] < '0' || data[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	Search_for_contact(int num_contacts, PhoneBook *phone_book)
{
	int			i;
	std::string	get_index;

	i = 0;
	while (i <= num_contacts)
	{
		std::cout << std::setw(10);
		std::cout << phone_book->get_contact(i).get_index();
		std::cout << "|";
		Print_One_Field(phone_book->get_contact(i).get_first_name());
		std::cout << "|";
		Print_One_Field(phone_book->get_contact(i).get_last_name());
		std::cout << "|";
		Print_One_Field(phone_book->get_contact(i).get_nickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "enter an index : ";
	std::getline (std::cin, get_index);
	if (std::cin.eof())
	{
		std::cerr << "reaching EOF\n";
		exit (1);
	}
	i = 0;
	while (i <= num_contacts && i < 8)
	{
		if (phone_book->get_contact(i).get_index() == std::atoi(get_index.data()) && is_number(get_index))
		{
			std::cout << "first name : " <<phone_book->get_contact(i).get_first_name() << std::endl;
			std::cout << "last name : " << phone_book->get_contact(i).get_last_name() << std::endl;
			std::cout << "nickname : " << phone_book->get_contact(i).get_nickname() << std::endl;
			std::cout << "phone number : " << phone_book->get_contact(i).get_phone_number() << std::endl;
			std::cout << "darkest secret : " << phone_book->get_contact(i).get_darkest_secret() << std::endl;
			return ;
		}
		i++;
	}
	std::cerr << "sorry! there is no contact with this index" << std::endl;
}


int main()
{
	int         num_contacts;
	std::string order;
	PhoneBook   phone_book;

	num_contacts = -1;
	while (1)
	{
		std::cout << "service :";
		std::getline (std::cin, order);
		if (std::cin.eof())
		{
			std::cerr << "sorry! the EOF has been reached\n";
			exit(1);
		}
		if (!order.compare("ADD"))
		{
			num_contacts = Add_contacts(num_contacts, &phone_book);
		}
		else if (!order.compare("SEARCH"))
		{
			Search_for_contact(num_contacts, &phone_book);
		}
		else if (!order.compare("EXIT"))
			exit(0);
		else
			std::cout << "The program only accepts ADD, SEARCH and EXIT." << std::endl;
	}
	return (0);
}