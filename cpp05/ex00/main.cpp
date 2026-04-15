#include "Bureaucrat.hpp"

int main()
{
    {
        Bureaucrat a;
        std::cout<<a;
    }

    std::cout<<std::endl;
    {
        Bureaucrat *a = new Bureaucrat;
        std::cout<<*a;
        delete a;
    }

    std::cout<<std::endl;
    {
        try
        {
            Bureaucrat a("test", 150);
            a.decr();
        }
        catch(const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr<<e.what()<<'\n';
        }
    }

    std::cout<<std::endl;
    {
        try
        {
            Bureaucrat a("test", 1);
            a.incer();
        }
        catch(const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr<<e.what()<<'\n';
        }
        
    }

    std::cout<<std::endl;
    {
        Bureaucrat a("test", 52);
        a.incer();
        std::cout<<a;
        a.decr();
        std::cout<<a;
    }
    return (0);
}
