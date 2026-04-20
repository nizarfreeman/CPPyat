#ifndef SERIALIZE
# define SERIALIZE
# include <iostream>
# include <stdint.h>

struct Data
{
    std::string str;
    int n;
};

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(Serializer const &other);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif