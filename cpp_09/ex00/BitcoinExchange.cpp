#include "BitcoinExchange.hpp"

// all class's needs
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data_map(other.data_map) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    this->data_map = other.data_map;
    return (*this);
}

// other member functions
float   BitcoinExchange::find_exchange_rate(std::string  date)
{
    for (std::map<std::string, float>::iterator it = data_map.begin(); it != data_map.end(); ++it)
    {
        if (date == it->first)
            return (it->second);
    }
    int year = std::atoi(date.substr(0, 4).data());
    int month = std::atoi(date.substr(5, 2).data());
    int day = std::atoi(date.substr(8, 2).data());
    if (year == 2009 && month == 1 && day == 1)
        throw SooomeException("Error: bad input => " + date);
    if (year == 2022 && (month > 3 || (month == 3 && day > 29)))
        return (data_map["2022-03-29"]);
    int lower_year;
    int lower_month;
    int lower_day;
    std::map<std::string, float>::iterator it = data_map.begin();
    for (; it != data_map.end(); ++it)
    {
        lower_year = std::atoi(it->first.substr(0, 4).data());
        lower_month = std::atoi(it->first.substr(5, 2).data());
        lower_day = std::atoi(it->first.substr(8, 2).data());
        if (lower_year >= year && lower_month >= month && lower_day >= day)
        {
            --it;
            break;
        }
    }
    return (it->second);
}

void    BitcoinExchange::fill_the_map()
{
    std::ifstream   data_file("data.csv");
    if (!data_file)
        throw SooomeException("Error: could not open data.csv file.");
    std::string     line;
    getline(data_file, line);
    while (getline(data_file, line))
    {
        data_map.insert(std::make_pair(line.substr(0, 10), std::stof(line.substr(11, line.length()))));
    }
}

void    BitcoinExchange::bitcoin_exchange(int ac, char **av)
{
    if (ac != 2)
        throw SooomeException("Error: could not open file.");
    std::ifstream inputfile(av[1]);
    if (!inputfile)
        throw SooomeException("Error: could not open file.");
    fill_the_map();
    std::string line;
    std::string _date;
    std::string _value;
    getline(inputfile, line);
    if (line != "date | value")
        throw SooomeException("the first line should be : [date | value]");
    while (getline(inputfile, line))
    {
        _date = line.substr(0, 10);
        int valid = 1;
        try
        {
            is_valid_date(_date);
            if (line.substr(10, 3) != " | ")
                throw SooomeException("Error: between date and value should be \" | \"");
            _value = line.substr(13, line.length());
            is_valid_value(_value);
        }
        catch(std::exception &e)
        {
            valid = 0;
            std::cout << e.what() << std::endl;
        }
        if(valid)
        {
            try
            {
                float _exchange_rate = find_exchange_rate(_date);
                std::cout << _date << " => " << _value << " = " << std::stof(_value) * _exchange_rate << std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

void    BitcoinExchange::is_valid_date(std::string date)
{
    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            throw SooomeException("Error: bad input => " + date);
        if ((i == 4 || i == 7) && date[i] != '-')
            throw SooomeException("Error: bad input => " + date);
    }
    int year = std::atoi(date.substr(0, 4).data());
    int month = std::atoi(date.substr(5, 2).data());
    int day = std::atoi(date.substr(8, 2).data());
    if (year < 2009 || year > 2022)
        throw SooomeException("Error: bad input => " + date);
    if (month < 1 || month > 12)
        throw SooomeException("Error: bad input => " + date);
    if (day < 1 || day > 31)
        throw SooomeException("Error: bad input => " + date);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw SooomeException("Error: range of \"30-day months\" [1---30] => " + date);
    /// last //
    if (month == 2 && day > 28)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && day == 29)
            return;
        throw SooomeException("Error: range of February [1---28] => " + date);
    }
}

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
        return (1);
    return (0);
}

int is_float(std::string input)
{
    unsigned long int i = 0;
    int check = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < input.length() && std::isdigit(input[i]))
    {
        check = 1;
        i++;
    }
    if (i < input.length() && input[i] == '.')
    {
        if (check == 1)
            check++;
        i++;
    }
    while (i < input.length() && std::isdigit(input[i]))
    {
        if (check >= 2)
            check = 3;
        i++;
    }
    if (i < input.length() && input[i] == 'f' && i + 1 == input.length())
        check++;
    if (check == 4)
        return (1);
    return (0);
}

int is_double(std::string input)
{
    unsigned long int i = 0;
    int check = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < input.length() && std::isdigit(input[i]))
    {
        check = 1;
        i++;
    }
    if (i < input.length() && input[i] == '.')
    {
        if (check == 1)
            check++;
        i++;
    }
    while (i < input.length() && std::isdigit(input[i]))
    {
        if (check >= 2)
            check = 3;
        i++;
    }
    if (check == 3 && i == input.length())
        return (1);
    return (0);
}

void    BitcoinExchange::is_valid_value(std::string value)
{
    if (!is_int(value) && !is_float(value) && !is_double(value))
        throw SooomeException("Error: unvalid number.");
    if (std::stoll(value) < 0)
        throw SooomeException("Error: not a positive number.");
    if (std::stoul(value) > 1000)
        throw SooomeException("Error: too large a number.");
}

///// SooomeException class /////
BitcoinExchange::SooomeException::SooomeException(std::string str) : text(str) {}
const char* BitcoinExchange::SooomeException::what() const throw()
{
    return (this->text.data());
}
BitcoinExchange::SooomeException::~SooomeException() throw() {}
/////////////////////////////////
