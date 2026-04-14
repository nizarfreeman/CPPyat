
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b("Bob", 66);
    b.incer();
    std::cout<<b;
    b.decr();
    std::cout<<b;

    // try
    // {
    //     Bureaucrat bb("Bob2", 151);
    // }
    // catch (const Bureaucrat::GradeTooLowException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }

    // try
    // {
    //     Bureaucrat bbb("Bob3", 0);
    // }
    // catch (const Bureaucrat::GradeTooHighException &e)
    // {
    //     std::cout<<e.what()<<std::endl;
    // }

    Bureaucrat a("alice", 88);
    a = b;
    std::cout<<a<<b;


    return 0;
}
