#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
 
RobotomyRequestForm::RobotomyRequestForm():
    AForm("RobotomyRequestForm", false, 72, 45), target("default")
{
    std::cout<<"RobotomyRequestForm default constructor called"<<std::endl;
}
 
RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
    AForm("RobotomyRequestForm", false, 72, 45), target(target)
{
    std::cout<<"RobotomyRequestForm parameterized constructor called"<<std::endl;
}
 
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):
    AForm(obj), target(obj.target)
{
    std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
}
 
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout<<"RobotomyRequestForm assignment operator called"<<std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
 
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<<"RobotomyRequestForm destructor called"<<std::endl;
}
 
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->gets())
        throw AForm::GradeTooLowException("Form is not signed");
    if (executor.getGrade() > this->geteg())
        throw AForm::GradeTooLowException("Bureaucrat's grade is too low to execute");
    std::cout<<"* drilling noises *"<<std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout<<this->target<<" has been robotomized successfully"<<std::endl;
    else
        std::cout<<this->target<<" robotomy failed"<<std::endl;
}