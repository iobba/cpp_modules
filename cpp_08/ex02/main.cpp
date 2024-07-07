#include "MutantStack.hpp"


int main()
{
    MutantStack<int> stack1;
    stack1.push(144);
    stack1.push(155);
    stack1.push(166);
    stack1.push(177);
    stack1.push(188);
    std::cout << "stack1 : \n\n";
    std::cout << "top = " << stack1.top() << std::endl;
    MutantStack<int>::iterator it = stack1.begin();
    MutantStack<int>::iterator ite = stack1.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "size = " << stack1.size() << std::endl;
    std::cout << "---------------------------------------\n";
    stack1.pop();
    stack1.push(200);
    std::cout << "stack1 : \n\n";
    std::cout << "top = " << stack1.top() << std::endl;
    it = stack1.begin();
    ite = stack1.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "size = " << stack1.size() << std::endl;
    std::cout << "\n-----------------using copy constructer----------------------\n";

    MutantStack<int> stack2(stack1);
    std::cout << "stack2 : \n\n";
    std::cout << "top = " << stack2.top() << std::endl;
    it = stack2.begin();
    ite = stack2.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "size = " << stack2.size() << std::endl;

    std::cout << "\n-----------------using copy assignment----------------------\n";

    MutantStack<int> stack3 = stack1;
    std::cout << "stack3 : \n\n";
    std::cout << "top = " << stack3.top() << std::endl;
    it = stack3.begin();
    ite = stack3.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "size = " << stack3.size() << std::endl;

    return (0);
}