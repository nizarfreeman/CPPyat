#ifndef SCALAR_
# define SCALAR_
# include <iostream>
# include <climits>
# include <cfloat>
# include <cmath>
# include <cstdlib>

enum e_type
{
    SPECIAL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID = -1
};

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter	&operator=(ScalarConverter const &obj);
        ~ScalarConverter();

        static void convert(std::string &literal);
};

void printSpecial(std::string &literal);
void printChar(std::string &literal);
void printInt(std::string &literal);
void printFloat(std::string &literal);
void printDouble(std::string &literal);

int is_special(std::string &literal);
int is_char(std::string &literal, size_t &len);
int is_int(std::string &literal);
int is_float(std::string &literal, size_t &len, size_t &dot);
int get_type(std::string &literal);


#endif