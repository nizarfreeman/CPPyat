#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout<<"Serialezer default constructor called"<<std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout<<"Serialezer copy constructor called"<<std::endl;
    *this = other;
}

Serializer &Serializer::operator=(Serializer const &other)
{
    std::cout<<"Serialezer assignment operator called"<<std::endl;
    if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Serializer::~Serializer()
{
    std::cout<<"Serializer destructor called"<<std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}