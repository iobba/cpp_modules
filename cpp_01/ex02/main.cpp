#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print memory address
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

    // Print the values
    std::cout << "The Value of the string variable: " << str << std::endl;
    std::cout << "The Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}