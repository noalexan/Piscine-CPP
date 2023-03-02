#include <iostream>
#include <iomanip>

void charPrint(char const a) {

	if (32 > a || a > 126) std::cout << "char: Non displayable" << std::endl;
	else std::cout << "char: '" << a << "'" << std::endl;

	const int i = static_cast<int>(a);
	std::cout << "int: " << i << std::endl;

	const float f = static_cast<float>(a);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

	const double d = static_cast<double>(a);
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;

}

void intPrint(int const a) {

	const char c = static_cast<char>(a);
	if (32 > c || c > 126) std::cout << "char: Non displayable" << std::endl;
	else std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << a << std::endl;

	const float f = static_cast<float>(a);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

	const double d = static_cast<double>(a);
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;

}

void floatPrint(float const a) {

	const char c = static_cast<char>(a);
	if (32 > c || c > 126) std::cout << "char: Non displayable" << std::endl;
	else std::cout << "char: '" << c << "'" << std::endl;

	if (INT_MIN <= a && a <= INT_MAX) std::cout << "int: " << static_cast<int>(a) << std::endl;
	else std::cout << "int: impossible" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: " << a << "f" << std::endl;

	const double d = static_cast<double>(a);
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;

}

void doublePrint(double const a) {

	const char c = static_cast<char>(a);
	if (32 > c || c > 126) std::cout << "char: Non displayable" << std::endl;
	else std::cout << "char: '" << c << "'" << std::endl;

	if (INT_MIN <= a && a <= INT_MAX) std::cout << "int: " << static_cast<int>(a) << std::endl;
	else std::cout << "int: impossible" << std::endl;

	if (__FLT_MAX__ <= a && a <= __FLT_MIN__) std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(a) << "f" << std::endl;
	else std::cout << "float: impossible" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "double: " << a << std::endl;

}

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Usage: " << ((argv[0]) ? argv[0] : "./ex00") << " [char | int | float | double]" << std::endl;
		return 1;
	}

	std::string	a(argv[1]);

	if (a == "nan" || a == "nanf")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: nanf" << std::endl << "double: nan" << std::endl;
	else if (a == "inf" || a == "+inf" || a == "inff" || a == "+inff")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: inff" << std::endl << "double: inf" << std::endl;
	else if (a == "-inf" || a == "-inff")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: -inff" << std::endl << "double: -inf" << std::endl;
	else {

		bool	number = false;
		bool	dot = false;
		bool	isFloat = false;
		bool	error = false;

		int	i = -1;
		while (a[++i]) {

			if ('0' <= a[i] && a[i] <= '9') {
				number = true;
			}

			if (a[i] == 'f' && number && dot && !a[i + 1]) {
				isFloat = true;
			}

			if (!(i == 0 && !a[1]) && ('0' > a[i] || a[i] > '9') && !isFloat && !(a[i] == '.' && !dot)) {
				error = true;
				break;
			}

			if (a[i] == '.' && number) {
				dot = true;
			}

		}

		if (error) {

			if (!number) {
				std::cerr << "Too many characters" << std::endl;
				return 2;
			}
			else {
				std::cerr << "There is a not-digit character" << ((dot) ? " or one more dot" : "") << std::endl;
				return 3;
			}

		}

		try {

			if (isFloat) floatPrint(std::stof(a));
			else if (dot) doublePrint(std::stod(a));
			else if (number) intPrint(std::stoi(a));
			else charPrint(a[0]);

		}
		catch (std::exception &) {
			std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
		}

	}

	return 0;

}
