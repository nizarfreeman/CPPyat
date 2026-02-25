#ifndef P_HPP
# define P_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <cctype>

class PresedentialPardonFrom : public AForm
{
    private:
        std::string target;
        PresedentialPardonFrom(): AForm("PresedentialPardonFrom", false, 25, 5)
        {
            std::cout<<"PresedentialPardonFrom default constructor called"<<std::endl;
        };
    public:
        PresedentialPardonFrom(std::string &name): AForm("PresedentialPardonFrom", false, 25, 5), target(name)
        {
            std::cout<<"PresedentialPardonFrom parameterized constructor called"<<std::endl;
        };
        PresedentialPardonFrom(PresedentialPardonFrom &obj): AForm("PresedentialPardonFrom", false, 25, 5), target(obj.get_terget())
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

        void execute(Bureaucrat const &executor) const
        {
            if (!this->gets())
                throw AForm::GradeTooLowException("Form is not signed");
            if (executor.getGrade() < this->geteg())
                throw AForm::GradeTooLowException("Bureaucrat's grade too low to execute");
            if (executor.getGrade() > this->getsg())
                throw AForm::GradeTooHighException("Bureaucrat's grade too high to execute");
            std::cout<<executor.getName()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
        };
        
        std::string get_terget(void) const
        {
            return (this->target);
        };
};


class RobotomyRequestForm: public AForm
{
    private:
        std::string target;
        RobotomyRequestForm(): AForm("RobotomyRequestForm", false, 72, 45)
        {
            std::cout<<"RobotomyRequestForm default constructor called"<<std::endl;
        };
    public:
        RobotomyRequestForm(std::string &name): AForm("RobotomyRequestForm", false, 72, 45), target(name)
        {
            std::cout<<"RobotomyRequestForm parameterized constructor called"<<std::endl;
        };
        RobotomyRequestForm(PresedentialPardonFrom &obj): AForm("RobotomyRequestForm", false, 72, 45), target(obj.get_terget())
        {
            std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
        };
        ~RobotomyRequestForm()
        {
            std::cout<<"RobotomyRequestForm deconstructor called"<<std::endl;
        };
        RobotomyRequestForm &operator=(RobotomyRequestForm &obj)
        {
            if (this != &obj)
                this->target = obj.get_terget();
            return (*this);
        };

        void execute(Bureaucrat const &executor) const
        {
            if (!this->gets())
                throw AForm::GradeTooLowException("Form is not signed");
            if (executor.getGrade() > this->geteg())
                throw AForm::GradeTooLowException("Bureaucrat's grade too low to execute");

            std::cout << "BZZZZZT DRRRRRR VRRRRM... drilling noises..." << std::endl;
            if (std::rand() % 2)
                std::cout << this->target << " has been robotomized successfully!" << std::endl;
            else
                std::cout << "Robotomy of " << this->target << " failed!" << std::endl;
        }
        
        std::string get_terget(void) const
        {
            return (this->target);
        };
};

#endif