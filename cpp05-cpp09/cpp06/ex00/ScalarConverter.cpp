#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

float stringToFloat(const std::string& str) {
    std::stringstream ss(str);
    float num;
    ss >> num;
    return num;
}

double stringToDouble(const std::string& str) {
    std::stringstream ss(str);
    double num;
    ss >> num;
    return num;
}

void ScalarConverter::convert(const std::string &input) {
    char    charValue = 0;
    int     intValue = 0;
    float   floatValue = 0.0f;
    double  doubleValue = 0.0;

    if (input.empty()) {
        std::cerr << RED "Error: input is empty" RESET << std::endl;
        return;
    }

    if (input == "nan" || input == "nanf") {
        std::cout << "char: " << CYAN "impossible" RESET << std::endl;
        std::cout << "int: " << CYAN "impossible" RESET << std::endl;
        std::cout << "float: " << CYAN "nanf" RESET << std::endl;
        std::cout << "double: " << CYAN "nan" RESET << std::endl;
        return;
    }

    if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff") {
        std::cout << "char: " << CYAN "impossible" RESET << std::endl;
        std::cout << "int: " << CYAN "impossible" RESET << std::endl;
        if (input[input.size() - 1] == 'f' && input.size() == 5) {
            std::cout << "float: " << CYAN << input << RESET << std::endl;
            std::cout << "double: " << CYAN << input.substr(0, input.size() - 1) << RESET << std::endl;
        } else {
            std::cout << "float: " << CYAN << input << "f" << RESET << std::endl;
            std::cout << "double: " << CYAN << input << RESET << std::endl;
        }
        return;
    }

    if (input == "inf" || input == "inff") {
        std::cout << "char: " << CYAN "impossible" RESET << std::endl;
        std::cout << "int: " << CYAN "impossible" RESET << std::endl;
        std::cout << "float: " << CYAN << input << RESET << std::endl;
        if (input.size() == 4) {
            std::cout << "double: " << CYAN << input.substr(0, input.size() - 1) << RESET << std::endl;
        } else {
            std::cout << "double: " << CYAN << input << RESET << std::endl;
        }
        return;
    }

    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
        charValue = input[0];
        intValue = static_cast<int>(charValue);
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
    } else if (input.find('.') == std::string::npos && input.find('f') == std::string::npos) {
        intValue = stringToInt(input);
        charValue = (intValue >= 0 && intValue <= 255 && std::isprint(intValue)) ? static_cast<char>(intValue) : 0;
        floatValue = static_cast<float>(intValue);
        doubleValue = static_cast<double>(intValue);
    } else if (input[input.size() - 1] == 'f') {
        floatValue = stringToFloat(input);
        doubleValue = static_cast<double>(floatValue);
        intValue = static_cast<int>(floatValue);
        charValue = 1;
    } else {
        doubleValue = stringToDouble(input);
        floatValue = static_cast<float>(doubleValue);
        intValue = static_cast<int>(doubleValue);
        charValue = 1;
    }

    if (charValue == 1 && !intValue && !floatValue && !doubleValue) {
        std::cout << RED "char: impossible" RESET << std::endl;
        std::cout << RED "int: impossible" RESET << std::endl;
        std::cout << RED "float: impossible" RESET << std::endl;
        std::cout << RED "double: impossible" RESET << std::endl;
    } else {
        std::cout << "char: ";
        if (charValue && std::isprint(charValue)) {
            std::cout << CYAN "'" << charValue << "'" RESET << std::endl;
        } else {
            if (charValue == 1) {
                std::cout << CYAN "'*'" RESET << std::endl;
            } else {
                std::cout << CYAN "Non displayable" RESET << std::endl;
            }
        }
        std::cout << "int: " << CYAN << intValue << RESET << std::endl;
        std::cout << "float: " << CYAN << std::fixed << std::setprecision(1) << floatValue << "f" RESET << std::endl;
        std::cout << "double: " << CYAN << std::fixed << std::setprecision(1) << doubleValue << RESET << std::endl;
    }
}