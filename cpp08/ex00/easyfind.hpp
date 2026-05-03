#ifndef E
# define E
# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T &arr, int n)
{
    typename T::iterator it;
    typename T::iterator it_end = arr.end();
    it = std::find(arr.begin(), it_end, n);
    if (it == it_end)
        throw std::runtime_error("value not found");
    return (it);
}

#endif