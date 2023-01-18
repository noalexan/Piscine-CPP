
#include <iostream>
#include <string>

std::string ft_to_upper(const std::string s) {
	size_t i = -1;
	std::string aa(s);

	while (s.length() > ++i)
		aa[i] = toupper(s[i]);

	return aa;
}

int main(int argc, char **argv) {
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	while (*++argv)
		std::cout << ft_to_upper(*argv);
	std::cout << std::endl;

	return 0;

}
