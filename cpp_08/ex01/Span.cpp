#include "Span.hpp"

long ft_abs(long a, long b)
{
    long hold = a - b;
    if (hold < 0)
        return (-hold);
    return (hold);
}

Span::Span() : _max(0) {}

Span::Span(unsigned int n)
{
    this->_max = n;
}

Span::Span(const Span& other)
{
    this->_max = other._max;
    this->arr = other.arr;
}

Span& Span::operator=(const Span& other)
{
    this->_max = other._max;
    this->arr = other.arr;
    return (*this);
}

unsigned int Span::get_max() const
{
    return (this->_max);
}

void    Span::addNumber(int elem)
{
    if (arr.size() < this->get_max())
        arr.push_back(elem);
    else
        throw OutOfRangeException();
}

void    Span::write_arr_elems() const
{
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << "elem " << i + 1 << ": " << arr[i] << std::endl;
}

unsigned int Span::shortestSpan() const
{
    unsigned int shortest_distance = std::numeric_limits<unsigned int>::max();

    if (arr.size() < 2)
        throw NotEnoughException();
    for (size_t i = 0; i < arr.size(); i++)
    {
        for(size_t j = i + 1; j < arr.size(); j++)
        {    
            unsigned int distance = ft_abs(arr[i], arr[j]);
            shortest_distance = std::min(shortest_distance, distance);
        }
    }
    return (shortest_distance);
}

unsigned int Span::longestSpan() const
{
    if (arr.size() < 2)
        throw NotEnoughException();
    std::vector<int>    arr_cp = arr;
    std::sort(arr_cp.begin(), arr_cp.end());
    return (ft_abs(arr_cp[0], arr_cp[arr_cp.size() - 1]));
}

void    Span::add_range(ITERATOR _begin, ITERATOR _end)
{
    if (std::distance(_begin, _end) + arr.size() > this->get_max())
        throw OutOfRangeException();
    else
        arr.insert(arr.end(), _begin, _end);
}

const char* Span::OutOfRangeException::what() const throw()
{
    return ("Exception : out of range");
}

const char* Span::NotEnoughException::what() const throw()
{
    return ("Exception : no enough elements");
}

Span::~Span() {}