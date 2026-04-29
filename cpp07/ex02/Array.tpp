#include "Array.hpp"

template <typename T>
Array<T>::Array(): arr(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array& other): arr(new T[other.size_]()), size_(other.size_)
{
    for (size_t i = 0; i < size_; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] arr;
        size_ = other.size_;
        arr = new T[size_]();
        for (size_t i = 0; i < size_; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return size_;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size_)
        throw outOfRange_ex("Index out of range");
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= size_)
        throw outOfRange_ex("Index out of range");
    return arr[index];
}

template <typename T>
Array<T>::outOfRange_ex::outOfRange_ex(): msg("error") {}

template <typename T>
Array<T>::outOfRange_ex::outOfRange_ex(std::string cmsg)
{
    msg = cmsg;
}

template <typename T>
const char* Array<T>::outOfRange_ex::what() const throw()
{
    return msg.c_str();
}

template <typename T>
Array<T>::outOfRange_ex::~outOfRange_ex() throw() {}