#ifndef DATA_HPP
#define DATA_HPP


class Data
{
    public :
        int i;
            Data();
        ~Data();
        Data(const Data &obj);
        Data& operator=(const Data &obj);
};

#endif