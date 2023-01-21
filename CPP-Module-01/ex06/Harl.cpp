#include "Harl.hpp"

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do !" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	e = -1;

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			e = i;

	switch (e) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
