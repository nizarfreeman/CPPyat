#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n)
{
    max_ = n;
}

Span::Span(const Span &other)
{
    max_ = other.getMax();
    data_ = other.data_;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        max_ = other.getMax();
        data_ = other.data_;
    }
    return (*this);
}

Span::~Span()
{
    
}

unsigned int Span::getMax() const
{
    return (this->max_);
}

void Span::addNumber(int n)
{
    if (data_.size() == max_)
        throw std::runtime_error("Max is reached, can't push any more value");
    data_.push_back(n);
}

int Span::longestSpan() const
{
    if (data_.size() <= 1)
        throw std::runtime_error("Not enough elements to find a span");
    int min = *std::min_element(data_.begin(), data_.end());
    int max = *std::max_element(data_.begin(), data_.end());
    return (max - min);
}

int Span::shortestSpan() const
{
    if (data_.size() <= 1)
        throw std::runtime_error("Not enough elements to find a span");
    std::vector<int> sorted = data_;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < shortest)
            shortest = diff;
    }
    return (shortest);
}