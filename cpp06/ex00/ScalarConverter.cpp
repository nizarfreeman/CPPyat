#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout<<"ScalarConverter default constructor called"<<std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout<<"ScalarConverter copy constructor called"<<std::endl;
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj)
{
    (void)obj;
    return (*this);
}

int is_special(std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf"
        || literal == "+inf" || literal == "nan")
        return (1);
    return (0);
}

int is_char(std::string &literal, size_t &len)
{
    if (len == 1 && !isdigit(literal[0]))
        return (1);
    if (len == 3 && literal[0] == '\'' && literal[2] == '\'' && !isdigit(literal[1]))
        return (1);
    return (0);
}

int is_int(std::string &literal, size_t &len)
{
    int i = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    if (!literal[i])
        return (0);
    while (literal[i])
    {
        if (!isdigit(literal[i]))
            return 0;
        i++;
    }
    long n = std::stol(literal);
    if (n > INT_MAX || n < INT_MIN)
        return 0;
    return (1);
}

int is_float(std::string &literal, size_t &len, size_t &dot)
{
    int i = 0;

    if (dot == 0 || dot == len - 2)
        return (0);
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (literal[i] && i < (int)dot)
    {
        if (!isdigit(literal[i]))
            return (0);
        i++;
    }
    i++;
    while (literal[i] && literal[i] != 'f')
    {
        if (!isdigit(literal[i]))
            return 0;
        i++;
    }
    if (literal[i] != 'f' || i != (int)(len - 1))
        return (0);
    return (1);
}

int get_type(std::string &literal)
{
    if (is_special(literal))
        return SPECIAL;
    
    size_t dot = literal.find('.');
    size_t f = literal.find('f');
    size_t len = literal.length();

    if (dot == std::string::npos)
    {
        if (is_char(literal, len))
            return CHAR;
        if (is_int(literal, len))
            return INT;
    }
    if (f != std::string::npos && dot != std::string::npos)
    {
        if (is_float(literal, len, dot))
            return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
        return DOUBLE;
    return INVALID;
}

void ScalarConverter::convert(std::string &literal)
{
    int type = get_type(literal);
    switch (type)
    {
        case INVALID:
            std::cout<<"Invalid Input"<<std::endl;
            break;
        case SPECIAL:
            printSpecial(literal);
            break;
        case CHAR:
            printChar(literal);
            break;
        case INT:
            printInt(literal);
            break;
        case FLOAT:
            printFloat(literal);
            break;
        case DOUBLE:
            printDouble(literal);
            break;
    }
}