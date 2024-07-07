#include "PmergeMe.hpp"

int is_int(std::string input)
{
    unsigned long int j = 0;
    unsigned long int i = 0; // compare with (unsigned long int (length))
    if (input[0] == '-' || input[0] == '+')
    {
        i++;
        j++;
    }
    while(i < input.length())
    {
        if (std::isdigit(input[i]))
            j++;
        i++;
    }
    if (j == i && j >= 1)
    {
        try
        {
            long long is_max = std::stoll(input);
            if (is_max > 2147483647 || is_max < 0)
                return (0);
        }
        catch(std::out_of_range& e)
        {
            (void)e;
            return (0);
        }
        return (1);
    }
    return (0);
}

int is_valid_args(int ac, char** av)
{
    for(int i = 1; i < ac; i++)
    {
        if (!is_int(av[i]))
            return (0);
    }
    return (1);
}

int main(int ac, char** av)
{
    PmergeMe        _merge_insert;

    if (ac < 2 || !is_valid_args(ac, av))
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    // fill the containers
    for(int i = 0; i < ac - 1; i++)
    {
        _merge_insert.add_number_vec(std::atoi(av[i + 1]));
        _merge_insert.add_number_lis(std::atoi(av[i + 1]));
    }

    std::cout << "Before:  ";
    _merge_insert.print_vec();
    
    // sort _vector
    std::clock_t vec_start = std::clock(); 
     _merge_insert.merge_sort_vec();
    std::clock_t vec_finish = std::clock();
    std::clock_t vec_time = vec_finish - vec_start;

    // sort _list
    std::clock_t list_start = std::clock();
    _merge_insert.merge_sort_lis();
    std::clock_t list_finish = std::clock();
    std::clock_t list_time = list_finish - list_start;


    std::cout << "After:   ";
    _merge_insert.print_vec();
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :  "
                                               << vec_time * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list :  "
                                               << list_time * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
    
}