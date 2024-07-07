#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b111", 90);
        Bureaucrat b2("b222", 150);
        Bureaucrat b3("b333", 1);
        Bureaucrat b4("b444", 50);

        std::cout << b1;
        std::cout << b2;
        std::cout << b3;

        //Bureaucrat b5("b555", 0);
        //Bureaucrat b5("b555", 151);
        //Bureaucrat b5("b555", 200);

        b3.decrement_grade();
        std::cout << b3;
        b3.increment_grade();
        std::cout << b3;
        b3.increment_grade();
    }
    catch(std::exception & e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
