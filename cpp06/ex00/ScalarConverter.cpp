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

ScalarConverter::~ScalarConverter()
{
    std::cout<<"ScalarConverter destructor called"<<std::endl;
}

//print special
void printSpecial(std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
	{
		std::cout<<"char: impossible"<<std::endl; 
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: nanf"<<std::endl;
		std::cout<<"double: nan"<<std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: +inff"<<std::endl;
		std::cout<<"double: +inf"<<std::endl;
    }
	
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: -inff"<< std::endl;
		std::cout<<"double: -inf"<< std::endl;
	}
}

//print char
void printChar(std::string &literal)
{
    char c;
    if (literal.length() == 3 && literal[0] == '\'')
        c = literal[1];
    else
        c = literal[0];
    if (std::isprint(c))
        std::cout<<"char: '"<<c<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    std::cout<<"int : "<<static_cast<int>(c)<<std::endl;
    std::cout<<"float: "<<static_cast<float>(c)<<"f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(c)<<std::endl;
}

//print int
void printInt(std::string &literal)
{
    long i = atol(literal.c_str());
    
    if (i >= 0 && i <= 127)
	{
		if (isprint(i))
			std::cout<<"char: '"<< static_cast<char>(i)<<"'"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
	}
    else
        std::cout<<"char: impossible"<<std::endl;
    
    std::cout << "int: ";
	if (i < INT_MIN || i > INT_MAX)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(i)<<std::endl;
	std::cout<<"float: "<<static_cast<float>(i)<<".0f"<<std::endl;
	std::cout<<"double: "<<static_cast<double>(i)<<".0"<<std::endl;
}

//print float
void printFloat(std::string &literal)
{
	float	f = atof(literal.c_str());
	bool	tol = (f == std::floor(f));

	std::cout<<"char: ";
	if (f < 0 || f > 127)
		std::cout<<"impossible"<<std::endl;
	else
	{
		if (isprint((int)f))
			std::cout<<"'"<<static_cast<char>(f)<<"'"<<std::endl;
		else
			std::cout<<"Non displayable"<<std::endl;
	}

	std::cout<<"int: ";
	if (f < INT_MIN || f > INT_MAX)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(f)<<std::endl;

	std::cout<<"float: ";
	if (f < -FLT_MAX || f > FLT_MAX)
		std::cout<<"impossible"<<std::endl;
	else
	{
		std::cout<<f;
		if (tol)
			std::cout<<".0f";
		else
			std::cout<<"f";
		std::cout<<std::endl;
	}

	std::cout<<"double: "<<static_cast<double>(f);
	if (tol)
		std::cout<<".0";
	std::cout<<std::endl;
}

//print double
void printDouble(std::string &literal)
{
	double	d = atof(literal.c_str());
	bool	tol = (d == std::floor(d));

	std::cout<<"char: ";
	if (d < 0 || d > 127)
		std::cout<<"impossible"<<std::endl;
	else
	{
		if (isprint((int)d))
			std::cout<<"'"<<static_cast<char>(d)<<"'"<<std::endl;
		else
			std::cout<<"Non displayable"<<std::endl;
	}

	std::cout<<"int: ";
	if (d < INT_MIN || d > INT_MAX)
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(d)<<std::endl;

	std::cout<<"float: ";
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout<<"impossible"<<std::endl;
	else
	{
		std::cout<<static_cast<float>(d);
		if (tol)
			std::cout<<".0f"<<std::endl;
		else
			std::cout<<"f"<<std::endl;
	}

	std::cout<<"double: ";
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout<<"impossible"<<std::endl;
	else
	{
		std::cout<<d;
		if (tol)
			std::cout<<".0";
		std::cout<<std::endl;
	}
}

//========================//
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

int is_int(std::string &literal)
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
    long n = atol(literal.c_str());
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
        if (is_int(literal))
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