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

void print_char(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void toDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
    {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
        return;
    }
    
    // Safe check: use modf to detect fractional part
    double intpart;
    if (std::modf(value, &intpart) == 0.0)
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << value << std::endl;
}

void toFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
    {
        std::cout << "nanf" << std::endl;
        toDouble(value);
        return;
    }
    if (std::isinf(value))
    {
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
        toDouble(value);
        return;
    }
    
    float result = static_cast<float>(value);
    
    // Check if conversion caused overflow
    if (std::isinf(result) && !std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        toDouble(value);
        return;
    }
    
    // Safe check: use modf to detect fractional part
    double intpart;
    if (std::modf(static_cast<double>(result), &intpart) == 0.0)
        std::cout << std::fixed << std::setprecision(1) << result << "f" << std::endl;
    else
        std::cout << result << "f" << std::endl;
    
    toDouble(value);
}

void toInt(double value)
{
    std::cout << "int: ";
    if (value > static_cast<double>(INT_MAX) || 
        value < static_cast<double>(INT_MIN) || 
        std::isnan(value) || 
        std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        toFloat(value);
        return;
    }
    std::cout << static_cast<int>(value) << std::endl;
    toFloat(value);
}

bool tonumbers(const std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);
    
    if (*endstr == '\0' || (*endstr == 'f' && *(endstr + 1) == '\0'))
    {
        print_char(value);
        toInt(value);
        return true;
    }
    return false;
}

bool toCHar(const std::string &str)
{

    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        double value = static_cast<double>(str[0]);
        print_char(value);
        toInt(value);
        return true;
    }
    
    return false;
}

void ScalarConverter::convert(const std::string& str)
{
    if (toCHar(str))
        return;
    if (tonumbers(str))
        return;
    
    std::cout << "Invalid input" << std::endl;
}