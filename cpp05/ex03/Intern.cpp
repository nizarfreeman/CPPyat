#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string forms[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    FormCreator creators[3] = {
        &Intern::createRobotomy,
        &Intern::createPresidential,
        &Intern::createShrubbery
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cerr << "Intern couldn't find form: " << name << std::endl;
    return NULL;
}