#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"

class BitcoinExchange
{
private:
	std::map<std::string, float> Prices;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

	void loadDatabase(const std::string &dbFile);
	void processInputFile(const std::string &inputFile);

private:
	float getExchangeRate(const std::string &date) const;
	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &value) const;
	std::string trim(const std::string &str) const;
};

#endif