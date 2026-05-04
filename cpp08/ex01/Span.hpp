#ifndef S
# define S
# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

class Span
{
    private:
        unsigned int max_;
        std::vector<int> data_;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        unsigned int getMax() const;

        void addNumber(int n);
        int longestSpan() const;
        int shortestSpan() const;
};

#endif