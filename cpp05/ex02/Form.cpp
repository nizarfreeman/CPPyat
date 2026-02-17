#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default form"), sign(false), s_grade(150), e_grade(150)
{
    std::cout << "Form default constructor called\n";
}

Form::Form(const std::string &namee, const bool &signn, const int &s_gradee, const int &e_gradee):  name(namee), sign(signn), s_grade(s_gradee), e_grade(e_gradee)
{
    if (s_grade < 1 || e_grade < 1)
        throw Form::GradeTooHighException("Can't initialize, too high s_grade / e_grade");
    if (s_grade > 150 || e_grade > 150)
        throw Form::GradeTooLowException("Can't initialize, too low s_grade / e_grade");
    std::cout << "Form parameterized constructor called\n";
}

std::string Form::getn(void) const
{
    return (this->name);
}

bool Form::gets(void) const
{
    return (this->sign);
}

int Form::getsg(void) const
{
    return (this->s_grade);
}

int Form::geteg(void) const
{
    return (this->e_grade);
}

Form::Form(const Form &obj): name(obj.getn()), sign(obj.gets()), s_grade(obj.getsg()), e_grade(obj.geteg())
{
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Form assignment operator called\n";
    if (this != &other)
        sign = other.gets();
    return (*this);
}

Form::GradeTooHighException::GradeTooHighException()
{
    message = "Form: GradeTooHighException error";
}

Form::GradeTooHighException::GradeTooHighException(const std::string &message)
{
    this->message = message;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return(message.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException()
{
    message = "Form: GradeTooLowException error";
}

Form::GradeTooLowException::GradeTooLowException(const std::string &message)
{
    this->message = message;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return(message.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form " << obj.getn() << " infos :" << std::endl
    << obj.gets() << " | " << obj.getsg() << " | " << obj.geteg() << std::endl;
    return (out);
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->s_grade)
        throw Form::GradeTooLowException();
    this->sign = true;
}