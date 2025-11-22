#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>   // Required for numeric_limits
#include <cmath>    // Required for huge_val, etc.
#include <cerrno>   // Required to detect strtod errors
#include <iomanip>  // Required for setprecision

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    double dVal = 0.0;
    bool impossible = false;

    // ---------------------------------------------------
    // STEP 1: DETECT TYPE AND PARSE TO DOUBLE
    // ---------------------------------------------------
    
    // Case A: Char Literal (e.g., 'a')
    // Logic: Length is 1, and it is NOT a digit.
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        dVal = static_cast<double>(literal[0]);
    }
    // Case B: Numbers or Special (inf, nan)
    else {
        char* endPtr;
        dVal = std::strtod(literal.c_str(), &endPtr);

        // Validation: If endPtr is not empty and not "f", input is garbage
        if (literal == "." || (endPtr[0] != '\0' && (endPtr[0] != 'f' || endPtr[1] != '\0'))) {
            impossible = true;
        }
    }

    // ---------------------------------------------------
    // STEP 2: PRINT WITH OVERFLOW PROTECTION
    // ---------------------------------------------------

    // --- CHAR ---
    std::cout << "char: ";
    // Check 1: Is it impossible input?
    // Check 2: Is it NaN? (NaN != NaN)
    // Check 3: Is it Infinity?
    // Check 4: OVERFLOW - Is it smaller than 0 or larger than 127 (Standard ASCII)?
    if (impossible || dVal != dVal || dVal == std::numeric_limits<double>::infinity() || 
        dVal == -std::numeric_limits<double>::infinity() || 
        dVal < 0 || dVal > 127) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(dVal))) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << static_cast<char>(dVal) << "'" << std::endl;
    }

    // --- INT ---
    std::cout << "int: ";
    // Check 1: Impossible input or NaN
    // Check 2: Overflow (Greater than Max Int or Less than Min Int)
    if (impossible || dVal != dVal || 
        dVal > std::numeric_limits<int>::max() || 
        dVal < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<int>(dVal) << std::endl;
    }

    // --- FLOAT ---
    std::cout << "float: ";
    if (impossible) {
        std::cout << "nanf" << std::endl;
    } else {
        // Handle -inff and +inff and nanf automatically
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(dVal) << "f" << std::endl;
    }

    // --- DOUBLE ---
    std::cout << "double: ";
    if (impossible) {
        std::cout << "nan" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << dVal << std::endl;
    }
}