#include <iostream>
#include <iomanip>

#include "PmergeMe.hpp"

void invalidArg(const char *arg, int where) {
	std::cout << "\e[1;31mInvalid argument: " << arg << std::endl << "                  ";
	for (int i = 0; arg[i]; ++i) std::cout << (i == where ? '^' : '~');
	std::cout << "\e[0m" << std::endl;
}

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Usage: " << (argv[0] ? argv[0] : "./PmergeMe") << " ..." << std::endl;
		return 1;
	}

	for (int i = 1; argv[i]; ++i) {
		if (!argv[i][0]) {
			invalidArg(argv[i], 0);
			return 1;
		}
		for (int j = 0; argv[i][j]; ++j) {
			if ('0' > argv[i][j] || argv[i][j] > '9') {
				invalidArg(argv[i], j);
				return 1;
			}
		}
		double d = std::stod(argv[i]);
		if (0 > d || d > INT_MAX) {
			invalidArg(argv[i], 0);
			return 1;
		}
	}

	PmergeMe pmm(argv + 1);

	std::cout << "Before:\t";
	for (std::deque<int>::iterator it = pmm.getDeque().begin(); it != pmm.getDeque().end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	pmm.sortDeque();
	pmm.sortVector();

	std::cout << "After:\t";
	for (std::deque<int>::iterator it = pmm.getDeque().begin(); it != pmm.getDeque().end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to sort a range of " << pmm.getSize() << " elements with std::vector : " << std::setprecision(6) << pmm.getVectorTime() << " ms" << std::endl;
	std::cout << "Time to sort a range of " << pmm.getSize() << " elements with std::deque  : " << std::setprecision(6) << pmm.getDequeTime() << " ms" << std::endl;

	return 0;
}
