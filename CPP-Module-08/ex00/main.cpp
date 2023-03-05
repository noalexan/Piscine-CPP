#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main() {
	std::vector<int>	a;

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	try {
		::easyfind< std::vector<int> >(a, 5);
		std::cout << "Value found" << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		::easyfind< std::vector<int> >(a, 50);
		std::cout << "Value found" << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
