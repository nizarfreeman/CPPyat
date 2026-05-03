#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>
#include <deque>

int main(void)
{
    std::vector<int> dbl_vec;
    dbl_vec.push_back(10);
    dbl_vec.push_back(20);
    dbl_vec.push_back(30);
    try
    {
        std::vector<int>::iterator it =  easyfind(dbl_vec, 10);
        std::cout<<*it<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<'\n';
    }

    std::list<int> str_l;
    str_l.push_front(10);
    str_l.push_front(20);
    str_l.push_front(30);
    try
    {
        std::list<int>::iterator it = easyfind(str_l, 40);
        std::cout<<*it<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr<<e.what()<<'\n';
    }
    
    std::deque<int> qu_;
    qu_.push_back(10);
    qu_.push_back(20);
    qu_.push_back(30);
    try
    {
        std::deque<int>::iterator it =  easyfind(qu_, 10);
        std::cout<<*it<<std::endl;
        it = easyfind(qu_, 50);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return (0);
}