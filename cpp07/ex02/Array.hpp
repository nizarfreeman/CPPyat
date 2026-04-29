#ifndef A_H
# define A_H
# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
    private:
        T* arr;
        unsigned int size_;
    public:
        Array(): arr(NULL), size_(0) {}
        Array(unsigned int n): arr(new T[n]()), size_(n) {}
        Array(const Array& other): arr(new T[other.size_]()), size_(other.size_)
        {
            for (size_t i = 0; i < size_; i++)
                arr[i] = other.arr[i];
        }
        Array& operator=(const Array& other)
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
        ~Array() { delete[] arr; }

        unsigned int size() const { return (size_); }

        T& operator[](unsigned int index)
        {
            if (index >= size_ )
                throw std::out_of_range("Index out of range");
            return arr[index];
        }
        
        const T& operator[](unsigned int index) const
        {
            if (index >= size_)
                throw std::out_of_range("Index out of range");
            return arr[index];
        }
};

#endif