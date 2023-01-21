#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cerr << "error: bad arguments" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);

	if (!in.is_open()) {
		std::cerr << "error: unable to open '" << argv[1] << "'" << std::endl;
		return 2;
	}

	std::ofstream out(std::string(argv[1]) + ".replace");

	if (!out.is_open()) {
		std::cerr << "error: unable to open '" << argv[1] << ".replace'" << std::endl;
		return 3;
	}

	std::string content;
	std::string line;
	while (std::getline(in, line))
		content += line + "\n";

	size_t i = 0;
	while ((i = content.find(argv[2], i)) != std::string::npos) {
		content = content.substr(0, i) + argv[3] + content.substr(i + strlen(argv[2]));
		i += strlen(argv[3]);
	}

	out << content;

	in.close();
	out.close();

	return 0;
}
