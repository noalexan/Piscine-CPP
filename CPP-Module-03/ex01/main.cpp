#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap a("a");
	ScavTrap b("b");

	a.attack("Mario");
	b.attack("mayoub");

	a.takeDamage(6);
	b.beRepaired(5);
	b.guardGate();
	a.beRepaired(3);

	return 0;
}
