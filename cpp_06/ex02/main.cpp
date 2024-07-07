#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(0));

    int i = std::rand() % 3;
    // std::cout << i << std::endl; // to ensure that identify() correct
    switch (i)
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    default :
        return (new C());
    }
}

void identify(Base* p)
{
    A* aa = dynamic_cast<A*>(p);
    if (aa == NULL)
    {
        B* bb = dynamic_cast<B*>(p);
        if (bb == NULL)
        {
            C* cc = dynamic_cast<C*>(p);
            if (cc == NULL)
                std::cout << "Unknown type of the object pointed to by p" << std::endl;
            else
                std::cout << "the actual type of the object pointed to by p is \"C\"" << std::endl;
        }
        else
            std::cout << "the actual type of the object pointed to by p is \"B\"" << std::endl;
    }
    else
        std::cout << "the actual type of the object pointed to by p is \"A\"" << std::endl;
}

void identify(Base& p)
{
    try{
        A& aa = dynamic_cast<A&>(p);
        (void)aa;
    }
    catch(std::bad_cast e)
    {
        try{
            B& bb = dynamic_cast<B&>(p);
            (void)bb;
        }
        catch(std::bad_cast e)
        {
            try{
                C& cc = dynamic_cast<C&>(p);
                (void)cc;
            }
            catch(std::bad_cast e)
            {
                std::cout << "Unknown type of the object pointed to by p" << std::endl;
                return ;
            }
            std::cout << "the actual type of the object pointed to by p is \"C\"" << std::endl;
            return ;
        }
        std::cout << "the actual type of the object pointed to by p is \"B\"" << std::endl;
        return ;
    }
    std::cout << "the actual type of the object pointed to by p is \"A\"" << std::endl;
}

int main()
{
    Base* base1 = generate();
    std::cout << "---------using pointer------------\n\n";
    identify(base1);
    std::cout << "\n---------using reference------------\n\n";
    identify(*base1);
}