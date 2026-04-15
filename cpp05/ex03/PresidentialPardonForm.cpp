#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
 
PresidentialPardonForm::PresidentialPardonForm():
    AForm("PresidentialPardonForm", false, 25, 5), target("default")
{
    std::cout<<"PresidentialPardonForm default constructor called"<<std::endl;
}
 
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): 
    AForm("PresidentialPardonForm", false, 25, 5), target(target)
{
    std::cout<<"PresidentialPardonForm parameterized constructor called"<<std::endl;
}
 
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):
    AForm(obj), target(obj.target)
{
    std::cout<<"PresidentialPardonForm copy constructor called"<<std::endl;
}
 
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout<<"PresidentialPardonForm assignment operator called"<<std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
 
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<<"PresidentialPardonForm destructor called"<<std::endl;
}
 
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->gets())
        throw AForm::GradeTooLowException("Form is not signed");
    if (executor.getGrade() > this->geteg())
        throw AForm::GradeTooLowException("Bureaucrat's grade is too low to execute");
    std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}