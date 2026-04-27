#ifndef ITER_H
# define ITER_H
# include <iostream>

template <typename T, typename U>
void iter(T *arr, size_t len, U func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif