#ifndef TEMPLATES_H
# define TEMPLATES_H
# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <typename T2>
T2 min(T2 a, T2 b)
{
    return (a < b) ? a : b;
}

template <typename T3>
T3 max(T3 a, T3 b)
{
    return (a < b) ? b : a;
}

#endif