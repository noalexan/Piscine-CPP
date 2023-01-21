#include "Zombie.hpp"

int main() {
	Zombie originel("originel");
	Zombie *horde = originel.zombieHorde(5, "slave");

	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
