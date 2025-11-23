#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"
class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &obj);
        Serializer& operator=(const Serializer &obj);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};
#endif