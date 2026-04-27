#ifndef ARRAY_
# define ARRAY_
# include <iostream>

template <typename T>
class Array
{
    private:
        T *arr;
        size_t len;
    public:
        Array() : arr(new T[0]()), len(0) {}
        Array(unsigned int n): arr(new T[n]()) len(n) {}
        Array(const Array *other)
        {
            
        }

};

#endif