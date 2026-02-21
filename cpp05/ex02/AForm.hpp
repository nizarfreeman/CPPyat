#ifndef F_HPP
# define F_HPP
# include <iostream>
# include <stdexcept>
  class Bureaucrat; 

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int s_grade;
        const int e_grade;
    public:

        std::string getn(void) const;
        bool gets(void) const;
        int getsg(void) const;
        int geteg(void) const;

        AForm();
        AForm(const std::string &namee, const bool &signn, const int &s_gradee, const int &e_gradee);
        AForm(const AForm &obj);
        virtual ~AForm();
        AForm &operator=(const AForm &other);

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

        void beSigned(const Bureaucrat &obj);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif