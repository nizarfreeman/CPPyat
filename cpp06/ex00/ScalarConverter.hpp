#ifndef SCALAR_
# define SCALAR_
# include <iostream>
# include <climits>
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

        // char int float double


        static void convert(std::string &literal);

};

#endif