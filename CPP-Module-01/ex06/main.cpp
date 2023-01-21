#include "Harl.hpp"

int main(int argc, char **argv) {
	(void) argc;

	if (argv && argv[1])
		Harl().complain(argv[1]);

	return 0;
}
