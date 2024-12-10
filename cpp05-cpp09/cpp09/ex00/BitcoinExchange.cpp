#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : Prices(other.Prices) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        Prices = other.Prices;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
        throw std::runtime_error(RED "Error: could not open database file." RESET);

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, price;

        if (std::getline(ss, date, ',') && std::getline(ss, price))
            Prices[date] = std::atof(price.c_str());
    }
    file.close();
}

bool check_is_valid(const std::string &valueStr, const std::string &line)
{
    bool hasDecimalPoint = false;
    for (size_t i = 0; i < valueStr.size(); i++)
    {
        char c = valueStr[i];

        if ((!isdigit(c) && c != '.' && c != '+') ||
            (c == '+' && i != 0) ||
            (c == '.' && (hasDecimalPoint || i == 0 || i == valueStr.size() - 1)))
        {
            std::cout << RED "Error: invalid input => " << line << RESET << std::endl;
            return false;
        }
        if (c == '.')
            hasDecimalPoint = true;
    }
    return true;
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error(RED "Error: could not open input file." RESET);

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = trim(date);
            if (date == "date")
                continue;
            valueStr = trim(valueStr);

            try
            {
                if (isValidDate(date) && isValidValue(valueStr))
                {
                    if (!check_is_valid(valueStr, line))
                        continue;
                    float value = std::atof(valueStr.c_str());
                    float rate = getExchangeRate(date);
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                }
                else
                    std::cout << RED "Error: invalid input => " << line << RESET << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else
        {
            std::cout << RED "Error: bad input format." RESET << std::endl;
        }
    }
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = Prices.lower_bound(date);
    if (it == Prices.begin() && it->first != date)
        throw std::runtime_error(RED "Error: no earlier date found in database." RESET);
    if (it->first != date)
        --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeapYear)
            return day <= 29;
        else
            return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
    return day <= 31;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    float v = std::atof(value.c_str());
    return v >= 0 && v <= 1000;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}