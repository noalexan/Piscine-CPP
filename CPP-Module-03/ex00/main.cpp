#include "ClapTrap.hpp"

int main() {
	ClapTrap a("a");

	a.attack("Mario");

	a.takeDamage(6);
	a.beRepaired(3);

	return 0;
}
