#include <fstream>
#include <map>

class BitcoinExchange {

	private:
		std::map<std::string, double> _data;

	public:

		BitcoinExchange();
		BitcoinExchange(std::string const &);
		BitcoinExchange(BitcoinExchange const &);

		BitcoinExchange & operator=(BitcoinExchange const &);

		~BitcoinExchange();

		void set(std::string date, double value);
		double get(std::string date);

		void compare(std::string date, double amount);

};
