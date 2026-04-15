#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
 
int main()
{
    Intern intern;

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "home");
    AForm* f3 = intern.makeForm("presidential pardon", "Bob");
    AForm* f4 = intern.makeForm("unknown form", "???");
    
    delete f1;
    delete f2;
    delete f3;
    delete f4;
}