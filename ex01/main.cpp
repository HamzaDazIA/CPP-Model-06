#include "Serializer.hpp"
#include "Data.hpp"


int main()
{
    Data p;
    p.i= 1337;

    uintptr_t type = Serializer::serialize(&p);
    std::cout << type << std::endl;
    Data * ptr = Serializer::deserialize(type);
    std::cout << ptr->i << std::endl;
}