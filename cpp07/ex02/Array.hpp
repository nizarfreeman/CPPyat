#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>
 
template <typename T>
class Array
{
    private:
        T*           arr;
        unsigned int size_;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
    
        unsigned int size() const;
    
        class outOfRange_ex : public std::exception
        {
        public:
            std::string msg;
        
            outOfRange_ex();
            outOfRange_ex(std::string cmsg);
            virtual const char* what() const throw();
            ~outOfRange_ex() throw();
        };
    
        T&       operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
};


#include "Array.tpp" 
 
#endif
