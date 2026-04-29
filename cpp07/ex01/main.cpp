#include "iter.hpp"

void mul_two(int &i)
{
    i *= 2;
}

void next_char(char &c)
{
    c += 1;
}

void testing(char &c)
{
    static int i = 0;
    std::cout<<c<<"-delivered ";
    if (i == 3)
        std::cout<<std::endl;
    i++;
}

template <typename T>
void print(T &c)
{
    std::cout<<c<<" ";
}

int main(void)
{
    std::string str = "nizar";
    int arr[] = {1, 2, 3};
    char c_str[] = "1337";
    const std::string const_test = "llm";

    iter(&str[0], str.length(),next_char);
    iter(&str[0], str.length(), print<char>);
    
    std::cout<<std::endl;

    iter(&arr[0], 3, mul_two);
    iter(&arr[0], 3, print<int>);
    
    std::cout<<std::endl;

    iter(&c_str[0], 4, print<char>);
    std::cout<<std::endl;
    iter(&const_test[0], 4, print<const char>);
    std::cout<<std::endl;

    return (0);
}
