
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b("John", 75);
        std::cout << b.get_n() << " grade: " << b.get_g() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Alice", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 200);
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
