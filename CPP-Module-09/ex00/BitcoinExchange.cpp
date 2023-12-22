#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

void invalid_format(std::string & line, int line_num, int where);

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const & databaseFileName) {

	std::ifstream database(databaseFileName);

	if (!database.is_open()) {
		std::cout << "Error opening file" << std::endl;
		throw std::exception();
	}

	std::string line;
	int line_num = 1;
	std::getline(database, line);
	while (std::getline(database, line)) {

		line_num++;

		if (line.length() < 11) { invalid_format(line, line_num, 0); exit(1); }

		// Verify format (XXXX-XX-XX,XXXXX.XX)
		for (int i = 0; i < 10; i++) {
			if (i == 4 || i == 7) { if (line[i] != '-') { invalid_format(line, line_num, i); exit(1); }}
			else if ('0' > line[i] || line[i] > '9') {invalid_format(line, line_num, i); exit(1);}
		}

		if (line[10] != ',') { invalid_format(line, line_num, 10); exit(1); }

		bool dot = false;
		for (size_t i = 11; i < line.length(); i++) {
			if ('0' > line[i] || line[i] > '9') {
				if (dot || line[i] != '.') { invalid_format(line, line_num, i); exit(1); }
				else dot = true;
			}
		}

		// Verify date
		std::string date = line.substr(0, line.find(','));

		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 0) { std::cerr << "\e[31;1mError: Invalid date: year must be over 0" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }
		if (month < 1 || month > 12) { std::cerr << "\e[31;1mError: Invalid date: month must be between 1 and 12" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }
		if (day < 1 || day > 31) { std::cerr << "\e[31;1mError: Invalid date: days must be between 1 and 31" << std::endl << line_num << ":\t" << line << std::endl; std::exception(); }

		if (month == 2) {
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
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
				std::cerr << "\e[31;1mError: Invalid date: This month doesn't have 31 days" << std::endl << line_num << ":\t" << line << std::endl;
				std::exception();
			}
		}

		double value = std::stod(line.substr(line.find(',') + 1));

		set(date, value);

	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy) {
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy) {
	_data.clear();
	_data = copy._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::set(std::string date, double value) {
	_data[date] = value;
}

double BitcoinExchange::get(std::string date) {

	std::map<std::string, double>::iterator it = _data.upper_bound(date);

	if (it != _data.begin()) {
		--it;
		return it->second;
	} else {
		throw std::exception();
	}

}

void BitcoinExchange::compare(std::string date, double amount) {

	std::cout << "On " << date << " you would have " << amount << " BTC, so " << amount * get(date) << " USD." << std::endl;

}
