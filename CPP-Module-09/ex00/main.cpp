#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

void invalid_format(std::string & line, int line_num, int where) {
	std::cerr << "\e[31;1mError: Invalid format" << std::endl;
	std::cerr << line_num << ":\t" << line << std::endl << "\t";
	for (int j = 0; j < (int) line.length(); j++) if (j == where) std::cerr << "^"; else std::cerr << "~";
	std::cerr << "\e[0m" << std::endl;
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "\e[31;1mError: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << (argv[0] ? argv[0] : "./btc") << " <file>" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "\e[31;1mError: Couldn't open input.txt" << std::endl;
		return 1;
	}

	BitcoinExchange exchange("data.csv");

	std::string line;
	std::getline(inputFile, line);
	int line_num = 1;
	while (std::getline(inputFile, line)) {

		bool error = false;
		line_num++;

		if (line.length() < 14) { invalid_format(line, line_num, 0); error = true; }

		// Verify format (XXXX-XX-XX | XXXXX.XX)
		for (int i = 0; i < 10 && !error; i++) {
			if (i == 4 || i == 7) { if (line[i] != '-') { invalid_format(line, line_num, i); error = true; }}
			else if (i == 10) { if (line[i] != ' ') { invalid_format(line, line_num, i); error = true; }}
			else if ('0' > line[i] || line[i] > '9') { invalid_format(line, line_num, i); error = true; }
		}

		if ((line[11] != '|' || line[12] != ' ') && !error) { invalid_format(line, line_num, 10); error = true; }

		bool dot = false;
		for (size_t i = 13; i < line.length() && !error; i++) {
			if ('0' > line[i] || line[i] > '9') {
				if (dot || line[i] != '.') { invalid_format(line, line_num, i); error = true; }
				else dot = true;
			}
		}

		// Verify date
		std::string date = line.substr(0, line.find(','));

		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 0 && !error) { std::cerr << "\e[31;1mError: Invalid date: year must be over 0" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }
		if ((month < 1 || month > 12) && !error) { std::cerr << "\e[31;1mError: Invalid date: month must be between 1 and 12" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }
		if ((day < 1 || day > 31) && !error) { std::cerr << "\e[31;1mError: Invalid date: days must be between 1 and 31" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }

		if (month == 2 && !error) {
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
				if (day > 29) {
					std::cerr << "\e[31;1mError: Invalid date: February has only 29 days within leap year" << std::endl << line_num << ":\t" << line << std::endl;
					std::exception();
				}
			} else {
				if (day > 28) {
					std::cerr << "\e[31;1mError: Invalid date: February has only 28 days without leap year" << std::endl << line_num << ":\t" << line << std::endl;
					std::exception();
				}
			}
		} else if ((month == 4 || month == 6 || month == 9 || month == 11) && !error) {
			if (day > 30) {
				std::cerr << "\e[31;1mError: Invalid date: This month doesn't have 31 days" << std::endl << line_num << ":\t" << line << std::endl;
				std::exception();
			}
		}

		// Verify amount
		double amount = std::stod(line.substr(line.find('|') + 1, line.length()));

		if ((INT_MIN > amount || amount > INT_MAX) && !error) { invalid_format(line, line_num, line.find('|') + 2); error = true; }

		if (!error) exchange.compare(date, amount);

	}

	return 0;
}
