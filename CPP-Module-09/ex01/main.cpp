#include "RPN.hpp"
#include <iostream>

void invalidCharacter(char * str, int i) {
	std::cout << "Error: invalid character: " << str << std::endl << "                          ";
	for (int j = 0; str[j]; j++) if (j == i) std::cout << '^'; else std::cout << '~';
	std::cout << std::endl;
}

int main(int argc, char **argv) {

	ReversePolishNotation RPN;

	if (argc != 2) {
		std::cout << "Usage: " << (argv[0] ? argv[0] : "./RPN") << " ..." << std::endl;
		return 1;
	}

	int i = 0;
	while (argv[1][i]) {

		while (argv[1][i] == ' ') i++;

		if (!argv[1][i]) break;

		if (argv[1][i] && !('0' <= argv[1][i] && argv[1][i] <= '9') && !(argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/')) {
			invalidCharacter(argv[1], i);
			return 1;
		}

		i++;

		if (argv[1][i] && argv[1][i] != ' ') {
			invalidCharacter(argv[1], i);
			return 1;
		}

		if ('0' <= argv[1][i - 1] && argv[1][i - 1] <= '9') RPN.add(argv[1][i - 1] - '0');
		else {

			if (RPN.size() < 2) {
				std::cout << "Error: not enought expression" << std::endl;
				return 1;
			}

			switch (argv[1][i - 1]) {
				case '+':
					RPN.addition();
					break;
				case '-':
					RPN.substraction();
					break;
				case '*':
					RPN.multplication();
					break;
				case '/':
					RPN.division();
					break;
			}
		}

	}

	if (RPN.size() == 1) std::cout << RPN.top() << std::endl;
	else std::cout << "Error: not enought operator" << std::endl;

	return 0;
}
