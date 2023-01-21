#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i]._name = name;
	}
	return horde;
}
