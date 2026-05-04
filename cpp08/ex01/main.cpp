// #include "Span.hpp"

// int main(void)
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return (0);
// }

#include "Span.hpp"
#include <cstdlib>

int main(void)
{
    // basic test from subject
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "=== Basic Test ===" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;  // 14

    // 50000 values test
    std::cout << "\n=== 50000 values Test ===" << std::endl;
    Span big = Span(50000);
    srand(42);
    for (int i = 0; i < 50000; i++)
        big.addNumber(rand() % 1000000);
    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << big.longestSpan() << std::endl;

    // sequential test (known results)
    std::cout << "\n=== Sequential Test ===" << std::endl;
    Span seq = Span(50000);
    for (int i = 0; i < 50000; i++)
        seq.addNumber(i);
    std::cout << "Shortest span: " << seq.shortestSpan() << std::endl; // 1
    std::cout << "Longest span:  " << seq.longestSpan() << std::endl;  // 49999

    // exception tests
    std::cout << "\n=== Exception Tests ===" << std::endl;
    try {
        Span empty = Span(5);
        empty.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Empty span: " << e.what() << std::endl;
    }
    try {
        Span one = Span(5);
        one.addNumber(42);
        one.longestSpan();
    } catch (std::exception &e) {
        std::cout << "One element: " << e.what() << std::endl;
    }
    try {
        Span full = Span(3);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
        full.addNumber(4); // should throw
    } catch (std::exception &e) {
        std::cout << "Overflow: " << e.what() << std::endl;
    }

    return (0);
}