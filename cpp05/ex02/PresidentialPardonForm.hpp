#ifndef P_HPP
# define P_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresedentialPardonFrom : public AForm
{
    private:
        std::string target;
        PresedentialPardonFrom(): AForm("PresedentialPardonFrom", false, 72, 45)
        {
            std::cout<<"PresedentialPardonFrom default constructor called"<<std::endl;
        };
    public:
        PresedentialPardonFrom(std::string &name): AForm("PresedentialPardonFrom", false, 72, 45), target(name)
        {
            std::cout<<"PresedentialPardonFrom parameterized constructor called"<<std::endl;
        };
        PresedentialPardonFrom(PresedentialPardonFrom &obj): AForm("PresedentialPardonFrom", false, 72, 45), target(obj.get_terget())
        {
            std::cout<<"PresedentialPardonFrom copy constructor called"<<std::endl;
        };
        ~PresedentialPardonFrom()
        {
            std::cout<<"PresedentialPardonFrom deconstructor called"<<std::endl;
        };
        PresedentialPardonFrom &operator=(PresedentialPardonFrom &obj)
        {
            if (this != &obj)
                this->target = obj.get_terget();
            return (*this);
        };

        void execute(Bureaucrat const &executor)
        {
            if (!this->gets())
                throw AForm::GradeTooLowException("Form is not signed 1");
            if (executor.getGrade() > this->geteg())
                throw AForm::GradeTooLowException("Bureaucrat's grade too low to execute");
            if (executor.getGrade() > this->getsg())
                throw AForm::GradeTooHighException("Bureaucrat's grade too high to execute");
        };
        
        std::string get_terget(void) const
        {
            return (this->target);
        };
};

#endif