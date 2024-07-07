#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class   BitcoinExchange
{
    private:
        std::map<std::string , float>   data_map;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    bitcoin_exchange(int ac, char **av);
        void    is_valid_date(std::string date);
        void    is_valid_value(std::string value);
        void    fill_the_map();
        float   find_exchange_rate(std::string  date);

        class   SooomeException : public std::exception
        {
            private:
                std::string   text;
            public:
                SooomeException(std::string str);
                const char* what() const throw();
                ~SooomeException() throw();
        };
};

#endif