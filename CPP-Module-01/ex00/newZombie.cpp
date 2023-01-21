#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string _name) {
	return new Zombie(_name);
}
