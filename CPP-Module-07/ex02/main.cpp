#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> def;

	try {
		def[42] = 42;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	int	size = 20;
	Array<int> test(size);

	for (int i = 0; i < size; i++)
		test[i] = i;

	for (int i = 0; i < size; i++)
		std::cout << test[i] << ' ';
	std::cout << std::endl;
	
	Array<int> test2(test);

	// std::cout << "Here!" << std::endl;

	try {
		test[20] = 42;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	test[19] = 42;

	for (int i = 0; i < size; i++)
		std::cout << test[i] << ' ';
	std::cout << std::endl;

	for (int i = 0; i < size; i++)
		std::cout << test2[i] << ' ';
	std::cout << std::endl;

	size = 20;
	Array<char> test3(size);

	for (int i = 0; i < size; i++)
		test3[i] = i + 48;

	for (int i = 0; i < size; i++)
		std::cout << test3[i] << ((i >= 10) ? "  " : " ");
	std::cout << std::endl;

	return 0;
}