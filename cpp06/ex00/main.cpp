#include "ScalarConverter.hpp"
#include <iostream>

int    main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return (1);
    }
    std::string literal(av[1]);
    ScalarConverter::convert(literal);
    return (0);
}