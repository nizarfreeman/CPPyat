#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    this->name = other.getName();
    this->grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout<<"Bureaucrat assignment operator called"<<std::endl;
    if (this != &other)
    {
        this->name = other.getName();
        this->grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat deconstructor called"<<std::endl;
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

void Bureaucrat::incer(void)
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException("Bureaucrat's grade already the highest possible !");
    this->grade--;
}

void Bureaucrat::decr(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException("Bureaucrat's grade already the lowest possible !");
    this->grade++;
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (out);
}

void Bureaucrat::signForm(Form &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->name << " signed " << obj.getn() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn't sign " << obj.getn() << " because "<< e.what() << ".\n";
    }
    
}