#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <chrono>
#include <ctime>

class   PmergeMe
{
    private:
        std::vector<int> _vector;
        std::list<int> _list;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    merge_sort_vec();
        void    merge_sort_lis();


        void    add_number_vec(int a);
        void    add_number_lis(int a);
        int     get_size_vec() const;
        int     get_size_lis() const;
        void    print_vec();
        void    print_lis();

};




#endif