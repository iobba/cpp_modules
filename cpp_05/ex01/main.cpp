#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b111", 90);
        Bureaucrat b2("b222", 150);
        Bureaucrat b3("b333", 1);

        std::cout << b1;
        std::cout << b2;
        std::cout << b3;

        ///// beSigned  ////
        Form f1("form1", 10, 20);
        std::cout << f1;
        f1.beSigned(b3);
        //f1.beSigned(b1);
        std::cout << f1;

        ///// signForm ///
        Form f2("form2", 100, 20);
        b1.signForm(f2);
        b2.signForm(f2);

    }
    catch(std::exception & e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
