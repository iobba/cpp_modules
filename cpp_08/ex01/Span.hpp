#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#define ITERATOR std::vector<int>::iterator

class   Span
{
    private:
        unsigned int _max;
        std::vector<int>  arr;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);

        unsigned int    get_max() const;
        void            addNumber(int elem);
        void            add_range(ITERATOR _begin, ITERATOR _end);
        void            write_arr_elems() const;
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;

        class   OutOfRangeException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class   NotEnoughException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        ~Span();

};




#endif