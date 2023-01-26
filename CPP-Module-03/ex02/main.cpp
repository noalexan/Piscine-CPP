#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap a("a");
	ScavTrap b("b");
	FragTrap c("c");

	a.attack("Mario");
	b.attack("mayoub");
	c.attack("mtaouil");

	c.takeDamage(10);
	a.takeDamage(6);
	b.beRepaired(5);
	a.beRepaired(3);
	b.guardGate();
	c.highFivesGuys();

	return 0;
}
