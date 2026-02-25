#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string &name);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
        void execute(Bureaucrat const &executor) const;
};
#endif