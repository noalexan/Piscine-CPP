#include "Zombie.hpp"

Zombie::Zombie(std::string _name): name(_name) {}
Zombie::~Zombie() { std::cout << name << " - destroyed" << std::endl; }

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
