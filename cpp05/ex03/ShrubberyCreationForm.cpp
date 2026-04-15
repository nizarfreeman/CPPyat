#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
 
ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("ShrubberyCreationForm", false, 145, 137), target("default")
{
    std::cout<<"ShrubberyCreationForm default constructor called"<<std::endl;
}
 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
    AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{
    std::cout<<"ShrubberyCreationForm parameterized constructor called"<<std::endl;
}
 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target, const bool &sign, const int &s_grade, const int &e_grade):
    AForm("ShrubberyCreationForm", sign, s_grade, e_grade), target(target)
{
    std::cout<<"ShrubberyCreationForm full parameterized constructor called"<<std::endl;
}
 
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):
    AForm(obj), target(obj.target)
{
    std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
}
 
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout<<"ShrubberyCreationForm assignment operator called"<<std::endl;
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}
 
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}
 
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->gets())
        throw AForm::GradeTooLowException("Form is not signed");
    if (executor.getGrade() > this->geteg())
        throw AForm::GradeTooLowException("Bureaucrat's grade is too low to execute");
    std::ofstream file;
    file.open((this->target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    file<<"       _|_       "<<std::endl;
    file<<"      /   \\      "<<std::endl;
    file<<"     /~~~~~\\     "<<std::endl;
    file<<"    / ~~~~~ \\    "<<std::endl;
    file<<"   /~~~~~~~~~\\   "<<std::endl;
    file<<"       | |       "<<std::endl;
    file.close();
}