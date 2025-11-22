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

bool    toCHar(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        int i = static_cast<int>(str[0]);
        std::cout << "char : ";
        if (i >= 0 && i <= 127)
        {
            if (!std::isprint(i))
            {
                std::cout << "impossible" << std::endl ; 
                return true;
            }
            std::cout << static_cast<char>(i) << std::endl;
        }
        return (true);
    }
    return (false);
     
}

bool toInt(std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);
    if (*endstr == '\0' || (*endstr == 'f' && *(endstr + 1) == '\0'))
    {
        std::cout << "int : ";
        if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN) || std::isnan(value))
        {
            std::cout << "impossible" << std::endl;
            return (true);
        }
        std::cout << static_cast<int>(value) << std::endl;
        return (true);
    }
    return (false);
} 



bool toFloat(const std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);

    if (*endstr == 'f' && *(endstr + 1) == '\0')
    {
        std::cout << "float : ";
        if (std::isnan(value))
        {
            std::cout << "nanf" << std::endl;
            return true;
        }
        if (std::isinf(value))
        {
            std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
            return true;
        }
        if (value > std::numeric_limits<float>::max() ||
            value < -std::numeric_limits<float>::max())
        {
            std::cout << "impossible" << std::endl;
            return true;
        }
        float result = static_cast<float>(value);
        if (result == static_cast<float>(static_cast<int>(result)))
            std::cout << static_cast<int>(result) << ".0f" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(6) << result << "f" << std::endl;

        return true;
    }
    return false;
}

bool toDouble(const std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);
    if ((*endstr == 'f' && *(endstr + 1) == '\0') || *endstr == '\0')
    {
        std::cout << "double : ";
        if (std::isnan(value))
        {
            std::cout << value << std::endl;
            return true;
        }
        if (std::isinf(value))
        {
            std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
            return true;
        }
        if (value > std::numeric_limits<double>::max() ||
            value < -std::numeric_limits<double>::max())
        {
            std::cout << "impossible" << std::endl;
            return true;
        }
        if (value == static_cast<double>(static_cast<int>(value)))
            std::cout << static_cast<int>(value) << ".0" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(6) << value << std::endl;
        return true;
    }
    return false;
}
void ScalarConverter::convert(std::string str)
{
    if (toCHar(str) == true) {}
    else if (toInt(str) == true) {}
    else if (toFloat(str) == true) {}
    else if (toDouble(str) == true) {}
    else
    {
        std::cout << "Invalid input" << std::endl;
    }

}