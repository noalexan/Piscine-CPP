#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {

	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		void complain(std::string);

};

#endif
