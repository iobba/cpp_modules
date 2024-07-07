#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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


		Intern intern;
		AForm* pr1 = intern.makeForm("presidential pardon", "pr1");
		AForm* ro1 = intern.makeForm("robotomy request", "ro1");
		AForm* wr = intern.makeForm("wrong form", "wrooooong");
		if (!wr)
			std::cout << "wr is NULL AForm pointer" << std::endl;

		////// sign /////
		std::cout << "\n---------------sign PresidentialPardonForm ---------------------\n\n";
		std::cout << pr1->getName() << std::endl;
		pr1->beSigned(b3);
		std::cout << "\n---------------sign RobotomyRequestForm ---------------------\n\n";
		std::cout << ro1->getName() << std::endl;
		ro1->beSigned(b3);


		/////// execute /////
		std::cout << "\n---------------execute PresidentialPardonForm ---------------------\n\n";
		pr1->execute(b3);
		//pr1.execute(b1);
		std::cout << "\n---------------execute RobotomyRequestForm ---------------------\n\n";
		ro1->execute(b3);
		ro1->execute(b1);
		ro1->execute(b2);

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return 0;
}
