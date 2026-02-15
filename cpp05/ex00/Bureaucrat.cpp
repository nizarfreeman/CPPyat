#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name,const  int &grade): name(name), grade(grade)
{
    std::cout<<"Bureaucrat paramaterized constructor called"<<std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout<<"Bureaucrat copy construcor called"<<std::endl;
    this->name = other.get_n();
    this->grade = other.get_g();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout<<"Bureaucrat assignment operator called"<<std::endl;
    if (this != &other)
    {
        this->name = other.get_n();
        this->grade = other.get_g();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat deconstructor called"<<std::endl;
}

int Bureaucrat::get_g(void) const
{
    return (this->grade);
}

std::string Bureaucrat::get_n(void) const
{
    return (this->name);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    message = "GradeTooHighException error";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message)
{
    this->message = message;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return(message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    message = "GradeTooLowException error";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message)
{
    this->message = message;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return(message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}