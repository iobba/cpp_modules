#include "BitcoinExchange.hpp"


int main(int ac, char** av)
{
    BitcoinExchange     bit1;
    try
    {
        bit1.bitcoin_exchange(ac, av);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
}