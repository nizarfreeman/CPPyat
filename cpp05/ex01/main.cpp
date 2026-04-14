#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat a("A", 2);
        std::cout << a;

        a.incer();
        std::cout << a;

        a.incer();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // try {
    //     Bureaucrat b("B", 150);
    //     std::cout << b;

    //     b.decr();
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat c("C", 1);
    //     Bureaucrat d = c;
    //     std::cout << d;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat e("E", 10);
    //     Bureaucrat f("F", 20);
    //     f = e;
    //     std::cout << f;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat g("G", 5);
    //     Form f1("F1", false, 1, 1);
    //     g.signForm(f1);
    //     std::cout << f1;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat h("H", 150);
    //     Form f2("F2", false, 100, 100);
    //     h.signForm(f2);
    //     std::cout << f2;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat *p = new Bureaucrat("PTR", 3);
    //     Form *f3 = new Form("F3", false, 2, 2);

    //     p->signForm(*f3);
    //     std::cout << *f3;

    //     delete p;
    //     delete f3;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Form f4("F4", false, 0, 10);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // try {
    //     Form f5("F5", false, 10, 200);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}
