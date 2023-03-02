#include <iostream>
#include "iter.hpp"

void increment(int &a) { a++; }

int main() {

	int ee[] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++)
		std::cout << ee[i] << std::endl;

	std::cout << std::endl;

	::iter<int>(ee, 5, increment);

	for (int i = 0; i < 5; i++)
		std::cout << ee[i] << std::endl;

	return 0;

}
