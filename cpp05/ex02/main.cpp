#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
 
int main()
{
    std::cout<<"\n=== TEST 1: Sign and execute PresidentialPardonForm ==="<<std::endl;
    try
    {
        Bureaucrat high("High", 1);
        PresidentialPardonForm ppf("Bob");
        high.signForm(ppf);
        high.executeForm(ppf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 2: Execute without signing ==="<<std::endl;
    try
    {
        Bureaucrat high("High", 1);
        PresidentialPardonForm ppf("Alice");
        high.executeForm(ppf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 3: Grade too low to sign ==="<<std::endl;
    try
    {
        Bureaucrat low("Low", 150);
        PresidentialPardonForm ppf("Charlie");
        low.signForm(ppf);
        low.executeForm(ppf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 4: Sign and execute RobotomyRequestForm ==="<<std::endl;
    try
    {
        Bureaucrat high("High", 1);
        RobotomyRequestForm rrf("target");
        high.signForm(rrf);
        high.executeForm(rrf);
        high.executeForm(rrf);
        high.executeForm(rrf);
        high.executeForm(rrf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 5: Sign and execute ShrubberyCreationForm ==="<<std::endl;
    try
    {
        Bureaucrat high("High", 1);
        ShrubberyCreationForm scf("home");
        high.signForm(scf);
        high.executeForm(scf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 6: Grade too low to execute RobotomyRequestForm ==="<<std::endl;
    try
    {
        Bureaucrat mid("Mid", 46);
        RobotomyRequestForm rrf("target");
        Bureaucrat signer("Signer", 1);
        signer.signForm(rrf);
        mid.executeForm(rrf);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
 
    std::cout<<"\n=== TEST 7: Invalid Bureaucrat grade ==="<<std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch(const std::exception &e)
    {
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
 
    return (0);
}