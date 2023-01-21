#include <iostream>
#include <string>

int main() {

	// Init variables
	std::string variable = "HI THIS IS BRAIN";
	std::string *variablePTR = &variable;
	std::string &variableREF = variable;
	std::cout << std::endl;

	// Print address of variables
	std::cout << "Address of variables" << std::endl;
	std::cout << &variable << std::endl;
	std::cout << &(*variablePTR) << std::endl;
	std::cout << &variableREF << std::endl;
	std::cout << std::endl;

	// Print value of variables
	std::cout << "Value of variables" << std::endl;
	std::cout << variable << std::endl;
	std::cout << *variablePTR << std::endl;
	std::cout << variableREF << std::endl;
	std::cout << std::endl;

	return 0;
}
