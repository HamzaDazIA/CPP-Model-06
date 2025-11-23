bool toFloat(const std::string &str)
{
    char *endstr;
    double value = std::strtod(str.c_str(), &endstr);

    // Check format: ends with 'f'
    if (*endstr == 'f' && *(endstr + 1) == '\0')
    {
        std::cout << "float : ";

        // -------------------------
        // 1. OVERFLOW CHECK
        // -------------------------
        if (value > std::numeric_limits<float>::max() ||
            value < std::numeric_limits<float>::lowest())
        {
            std::cout << "impossible" << std::endl;
            return true;
        }

        // No overflow → safe cast
        float fvalue = static_cast<float>(value);

        // -------------------------
        // 2. PRINT VALUE
        // -------------------------
        std::cout << fvalue;

        // Add ".0" for integers
        if (fvalue - static_cast<int>(fvalue) == 0)
            std::cout << ".0";

        std::cout << "f" << std::endl;
        return true;
    }

    return false;
}
