#include "Zombie.hpp"

int main() {
	Zombie tmp("Hearl 1.0");
	Zombie *tmp2;

	tmp.announce();

	tmp2 = tmp.newZombie("Hearl 2.0");

	tmp2->announce();

	tmp2->randomChump("Hearl 3.0");

	delete(tmp2);
}
