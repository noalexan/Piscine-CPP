#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other._name) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " entering in GateKeeper mode" << std::endl;
}
