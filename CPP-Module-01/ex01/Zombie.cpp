#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string name): _name(name) { announce(); }
Zombie::~Zombie() { std::cout << _name << " - destroyed" << std::endl; }
void Zombie::announce() { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
