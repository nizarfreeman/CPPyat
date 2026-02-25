#ifndef BU_HPP
# define BU_HPP
# include <iostream>
# include <stdexcept>
  class AForm;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int &grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName(void) const;
        int getGrade(void) const;
        void incer(void);
        void decr(void);

        void signForm(AForm &obj);
        
        class GradeTooHighException: public std::exception
        {
            private:
                std::string message;
            public:
                GradeTooHighException();
                GradeTooHighException(const std::string &message);
                ~GradeTooHighException() throw();
                const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            private:
                std::string message;
                public:
                GradeTooLowException();
                GradeTooLowException(const std::string &message);
                ~GradeTooLowException() throw();
                const char *what() const throw();
        };

        void executeForm(AForm const &form) const
        {
            try
            {
                form.execute(*this);  // pass *this not form
                std::cout << this->getName() << " executed " << form.getn() << std::endl;
            }
            catch (std::exception &e)
            {
                std::cerr << this->getName() << " couldn't execute " << form.getn()
                          << " because " << e.what() << std::endl;
            }
        }
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif