#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &obj){
    (void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return (*this);
}

void printAll(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        float f = static_cast<float>(value);
        if (f == static_cast<int>(f))
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }

    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        if (value == static_cast<int>(value))
            std::cout << value << ".0" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

bool    toCHar(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        printAll(static_cast<double>(str[0]));
        return (true);
    }
    return (false);
     
}

bool tonumber(std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);
    if (*endstr == '\0' || (*endstr == 'f' && *(endstr + 1) == '\0'))
    {
        printAll(value);
        return (true);
    }
    return (false);
} 



void ScalarConverter::convert(std::string str)
{
    if (toCHar(str)) {}
    else if (tonumber(str)) {}
    else
    {
        std::cout << "Invalid input" << std::endl;
    }
}