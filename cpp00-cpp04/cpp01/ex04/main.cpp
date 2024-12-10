#include <iostream>
#include <fstream>
#include <string>

#define RESET	"\033[0m"
#define BLUE	"\033[34m"
#define RED		"\033[31m"

std::string replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = line.find(s1, start)) != std::string::npos) {
        result.append(line, start, pos - start);
        result.append(s2);
        start = pos + s1.length();
    }
    result.append(line, start, std::string::npos);
    return result;
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << BLUE "Usage: " << av[0] << " <fileName> <s1> <s2>" RESET << std::endl;
		return 1;
	}

	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << RED "Error: s1 is empty" RESET << std::endl;
		return 1;
	}
	if (s2.empty()) {
		std::cerr << RED "Error: s2 is empty" RESET << std::endl;
		return 1;
	}

	std::ifstream inFile(fileName.c_str());
	if (!inFile.is_open()) {
		std::cerr << RED "Error: Can't open input file " << fileName << RESET << std::endl;
		return 1;
	}
	
	std::ofstream outFile(fileName.append(".replace").c_str());
	if (!outFile.is_open()) {
		std::cerr << RED "Error: Can't open output file " << fileName << RESET << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		outFile << replaceOccurrences(line, s1, s2) << std::endl;
	}

	inFile.close();
	outFile.close();
}
