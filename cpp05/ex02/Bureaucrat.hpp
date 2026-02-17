#ifndef BU_HPP
# define BU_HPP
# include <iostream>
# include <stdexcept>
  class Form;

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

        void signForm(Form &obj);
        
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
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif