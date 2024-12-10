#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define CYAN	"\033[36m"

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &);
        ScalarConverter &operator=(ScalarConverter const &);
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);
};

int stringToInt(const std::string& str);
float stringToFloat(const std::string& str);
double stringToDouble(const std::string& str);

#endif