#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default Form"), sign(false), s_grade(150), e_grade(150)
{
    std::cout << "Form default constructor called\n";
}

AForm::AForm(const std::string &namee, const bool &signn, const int &s_gradee, const int &e_gradee):  name(namee), sign(signn), s_grade(s_gradee), e_grade(e_gradee)
{
    if (s_grade < 1 || e_grade < 1)
        throw AForm::GradeTooHighException("Can't initialize, too high s_grade / e_grade");
    if (s_grade > 150 || e_grade > 150)
        throw AForm::GradeTooLowException("Can't initialize, too low s_grade / e_grade");
    std::cout << "Form parameterized constructor called\n";
}

std::string AForm::getn(void) const
{
    return (this->name);
}

bool AForm::gets(void) const
{
    return (this->sign);
}

int AForm::getsg(void) const
{
    return (this->s_grade);
}

int AForm::geteg(void) const
{
    return (this->e_grade);
}

AForm::AForm(const AForm &obj): name(obj.getn()), sign(obj.gets()), s_grade(obj.getsg()), e_grade(obj.geteg())
{
    std::cout << "Form copy constructor called\n";
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Form assignment operator called\n";
    if (this != &other)
        sign = other.gets();
    return (*this);
}

AForm::GradeTooHighException::GradeTooHighException()
{
    message = "Form: GradeTooHighException error";
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message)
{
    this->message = message;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return(message.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException()
{
    message = "Form: GradeTooLowException error";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message)
{
    this->message = message;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return(message.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "Form " << obj.getn() << " infos :" << std::endl
    << obj.gets() << " | " << obj.getsg() << " | " << obj.geteg() << std::endl;
    return (out);
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->s_grade)
        throw AForm::GradeTooLowException();
    this->sign = true;
}