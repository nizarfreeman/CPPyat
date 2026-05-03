#include "easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<double> dbl_vec;
    dbl_vec.push_back(10);
    dbl_vec.push_back(20);
    dbl_vec.push_back(30);

    try
    {
        std::vector<double>::iterator it =  easyfind(dbl_vec, 10);
        std::cout<<*it<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<'\n';
    }
    
    
    return (0);
}