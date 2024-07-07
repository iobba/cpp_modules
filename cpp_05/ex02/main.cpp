#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b111", 45);
		Bureaucrat b2("b222", 15);
		Bureaucrat b3("b333", 1);

		std::cout << b1;
		std::cout << b2;
		std::cout << b3;


		PresidentialPardonForm pr1("pr1");
		RobotomyRequestForm ro1("ro1");
		ShrubberyCreationForm sh1("sh1");

		////// sign /////
		std::cout << "\n---------------sign PresidentialPardonForm ---------------------\n\n";
		pr1.beSigned(b3);
		std::cout << "\n---------------sign RobotomyRequestForm ---------------------\n\n";
		ro1.beSigned(b3);
		std::cout << "\n---------------sign ShrubberyCreationForm ---------------------\n\n";
		sh1.beSigned(b3);


		/////// execute /////
		std::cout << "\n---------------execute PresidentialPardonForm ---------------------\n\n";
		pr1.execute(b3);
		//pr1.execute(b1);
		std::cout << "\n---------------execute RobotomyRequestForm ---------------------\n\n";
		ro1.execute(b3);
		ro1.execute(b1);
		ro1.execute(b2);
		std::cout << "\n---------------execute ShrubberyCreationForm ---------------------\n\n";
		sh1.execute(b3);

		std::cout << "\n---------------executeForm()---------------------\n\n";
		ShrubberyCreationForm sh2("shshshsh22222");
		//sh2.beSigned(b3);
		b3.executeForm(sh2);

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return 0;
}
