#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): AForm("ShrubberyCreationForm", false, 145, 137), target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm("ShrubberyCreationForm", false, 145, 137), target(obj.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
        this->target = obj.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->gets())
        throw AForm::GradeTooLowException("Form is not signed");
    if (executor.getGrade() > this->geteg())  // grade too LOW (number too high)
        throw AForm::GradeTooLowException("Bureaucrat's grade too low to execute");
    
    std::ofstream file(this->target + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    file << "       _|_       " << std::endl;
    file << "      /   \\      " << std::endl;
    file << "     /~~~~~\\     " << std::endl;
    file << "    / ~~~~~ \\    " << std::endl;
    file << "   /~~~~~~~~~\\   " << std::endl;
    file << "       | |       " << std::endl;
    file.close();
}