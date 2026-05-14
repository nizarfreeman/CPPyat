#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <exception>

void parse_data_(std::map<std::string, double> &data_)
{
    std::ifstream file("../data.csv");
    if (!file.is_open())
        throw std::runtime_error("coudln't open file");
    
    std::string line;
    getline(file, line);
    getline(file, line);

    while(getline(file, line))
    {
        std::string date;
        std::string rate;

        std::stringstream ss(line);
        getline(ss, date, ',');
        getline(ss, rate);

        data_[date] =  std::strtod(rate.c_str(), NULL);
    }
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// YYYY-MM-DD
bool evaluate_date_(std::string &str)
{
    if (str.length() != 10 || str[4] != '-' || str[7] != '-')
        return (false);
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(str[i]))
            return (false);
    }
    //
    // db -> map
    // load input
    // db + input = res
    int year  = std::atoi(str.substr(0, 4).c_str());
    int month = std::atoi(str.substr(5, 2).c_str());
    int day   = std::atoi(str.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return (false);
    if (day < 1)
        return (false);

    int daysInMonth[] =
    {
        31, // Jan
        28, // Feb
        31, // Mar
        30, // Apr
        31, // May
        30, // Jun
        31, // Jul
        31, // Aug
        30, // Sep
        31, // Oct
        30, // Nov
        31  // Dec
    };

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return (false);

    return (true);
}

bool evaluate_value_(std::string &str, double &value)
{
    if (str.empty())
        return (false);
    char *end;
    value = std::strtod(str.c_str(), &end);
    if (*end != '\0')
        return (false);
    if (value < 0 || value > 1000)
        return (false);
    return (true);
}

void process_(std::map<std::string, double> &data_, const char *input_)
{
    std::ifstream file(input_);
    if (!file.is_open())
        throw std::runtime_error("couldn't open input file");
    std::string line;
    getline(file, line);

    std::string date;
    std::string value;
    double value_;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        if (!getline(ss, date, '|') || !getline(ss, value))
        {
            // throw std::runtime_error("Error: bad input => ");
            std::cout<<"Error: bad input, [YXXX-MX-DX | value]"<<std::endl;
            continue;
        }
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        if (!evaluate_date_(date))
        {
            // throw std::runtime_error("Error: malformed date");
            std::cout<<"Error: malformed date => "<<date<<std::endl;
            continue;
        }
        if (!evaluate_value_(value, value_))
        {
                // throw std::runtime_error("Error: invalid value");
            std::cout<<"Error: Invalid value => "<<value_<<std::endl;
            continue;
        }
        else
            std::cout<<date<<" "<<value<<std::endl;
    }
}

// date | value, dates in the year, month, dat + the value
int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<<"Use: ./btc [input_file]"<<std::endl;
        return (1);
    }

    std::map<std::string, double> data_;
    try
    {
        parse_data_(data_);
        process_(data_, av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}