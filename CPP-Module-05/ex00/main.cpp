#include <iostream>

#include "Bureaucrat.hpp"

int main() {

	std::cout << std::endl;

	// Test 1
	{
		Bureaucrat a("name", 10);

		std::cout << a << std::endl;
	}

	std::cout << std::endl;

	// Test 2
	{
		Bureaucrat a("name", 10);
		Bureaucrat b("no name", 149);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a = b;
		std::cout << a << std::endl;
		a++;
		b--;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	std::cout << std::endl;

	// Test 3
	{

		try {
			Bureaucrat a("name", 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			Bureaucrat b("name", 160);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

	}

	std::cout << std::endl;

	return 0;
}
