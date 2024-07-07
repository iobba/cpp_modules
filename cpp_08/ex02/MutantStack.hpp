#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other)  : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator   begin()
        {
            return this->c.begin();
        }

        iterator   end()
        {
            return this->c.end();
        }

        ~MutantStack() {}
};


#endif