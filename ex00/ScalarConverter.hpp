#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <string>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter& operator=(const ScalarConverter &obj);
    public:
        static void convert(const std::string& str);

};
#endif