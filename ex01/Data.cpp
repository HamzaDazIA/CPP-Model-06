#include "Data.hpp"


Data::Data(){}
Data::~Data(){}
Data::Data(const Data &obj){
    this->i = obj.i;
}

Data& Data::operator=(const Data &obj)
{
    this->i = obj.i;
    return (*this);
}
