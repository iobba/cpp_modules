#include "PmergeMe.hpp"

// all class's needs
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _list(other._list) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    this->_vector = other._vector;
    this->_list = other._list;
    return (*this);
}
PmergeMe::~PmergeMe() {}

void insert_sort(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void    PmergeMe::merge_sort_vec()
{
    int is_odd = false;
    if (_vector.size() < 2)
        return ;
    if (_vector.size() % 2 != 0)
        is_odd = true;
    // make pairs and sort them
    unsigned int i = 0;
    while (i < _vector.size() - 1)
    {
        if (_vector[i] > _vector[i + 1])
            std::swap(_vector[i], _vector[i + 1]);
        i += 2;
    }
    // gather all smallers and greaters
    std::vector<int> small_arr;
    std::vector<int> great_arr;
    i = 0;
    while (i < _vector.size() - 1)
    {
        small_arr.push_back(_vector[i]);
        great_arr.push_back(_vector[i + 1]);
        i +=2;
    }
    // sort the small_arr using insertion sort algorithm
    insert_sort(small_arr, 0, small_arr.size() - 1);
    std::vector<int>::iterator it = great_arr.begin();
    std::vector<int>::iterator _first_great;
    while (it != great_arr.end())
    {
        _first_great = std::lower_bound(small_arr.begin(), small_arr.end(), *(it));
        if (_first_great == small_arr.end())
            small_arr.push_back(*(it));
        else
            small_arr.insert(_first_great, it, it + 1);
        it++;
    }
    if (is_odd)
    {
        _first_great = std::lower_bound(small_arr.begin(), small_arr.end(), *(--_vector.end()));
        if (_first_great == small_arr.end())
            small_arr.push_back(*(--_vector.end()));
        else
            small_arr.insert(_first_great, --_vector.end(), _vector.end());
    }
    // fill _vector
    _vector = small_arr;
}

void    insertion_sort_lis(std::list<int> &_list_)
{
    for (std::list<int>::iterator it = std::next(_list_.begin()); it != _list_.end(); ++it)
    {
        int key = *it;
        std::list<int>::iterator prev_it = std::prev(it);
        while (prev_it != _list_.begin() && *prev_it > key)
        {
            std::swap(*prev_it, *it);
            --it;
            --prev_it;
        }
        if (*prev_it > key) //// when prev_it == _list_.begin()
        {
            std::swap(*prev_it, *it);
        }
    }
}

void    PmergeMe::merge_sort_lis()
{
    int is_odd = false;
    if (_list.size() < 2)
        return ;
    if (_list.size() % 2 != 0)
        is_odd = true;
    // make pairs and sort them
    std::list<int>::iterator it = _list.begin();
    while (it != std::prev(_list.end()) && it != _list.end())
    {
        if (*(it) > *(std::next(it)))
            std::swap(*(it), *(std::next(it)));
        it = std::next(std::next(it));
    }
    // gather all smallers and greaters
    std::list<int> small_arr;
    std::list<int> great_arr;

    it = _list.begin();
    while (it != std::prev(_list.end()) && it != _list.end())
    {
        small_arr.push_back(*(it));
        great_arr.push_back(*(std::next(it)));
        it = std::next(std::next(it));
    }
    // sort the small_arr using insertion sort algorithm
    insertion_sort_lis(small_arr);
    it = great_arr.begin();
    std::list<int>::iterator _first_great;
    while (it != great_arr.end())
    {
        _first_great = std::lower_bound(small_arr.begin(), small_arr.end(), *(it));
        if (_first_great == small_arr.end())
            small_arr.push_back(*(it));
        else
            small_arr.insert(_first_great, it, std::next(it));
        it++;
    }
    if (is_odd)
    {
        _first_great = std::lower_bound(small_arr.begin(), small_arr.end(), *(std::prev(_list.end())));
        if (_first_great == small_arr.end())
            small_arr.push_back(*(std::prev(_list.end())));
        else
            small_arr.insert(_first_great, std::prev(_list.end()), _list.end());
    }
    // fill _list
    _list = small_arr;
}

void    PmergeMe::add_number_vec(int a)
{
    _vector.push_back(a);
}

void    PmergeMe::add_number_lis(int a)
{
    _list.push_back(a);
}

int     PmergeMe::get_size_vec() const
{
    return (_vector.size());
}

int     PmergeMe::get_size_lis() const
{
    return (_list.size());
}

void    PmergeMe::print_vec()
{
    for (unsigned int i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::print_lis()
{
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
        std::cout << *(it) << " ";
    std::cout << std::endl;
}