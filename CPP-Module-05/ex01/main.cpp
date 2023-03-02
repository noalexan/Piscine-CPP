#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	std::cout << std::endl;

	// Test 1
	{
		Bureaucrat a("name", 10);
		Form b("namee", 5, 120);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	std::cout << std::endl;

	// Test 2
	{
		Bureaucrat a("name", 10);
		Form b("DDDDD", 10, 20);

		try {
			b.beSigned(a);
			if (b.isSigned())
				std::cout << b.getName() << " has been signed" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 3
	{
		Bureaucrat a("name", 10);
		Form b("DDDDD", 10, 20);

		try {
			a.signForm(b);
			if (b.isSigned())
				std::cout << b.getName() << " has been signed" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 4
	{
		Bureaucrat a("name", 30);
		Form b("DDDDD", 10, 20);

		try {
			a.signForm(b);
			if (b.isSigned())
				std::cout << b.getName() << " has been signed" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	return 0;
}
