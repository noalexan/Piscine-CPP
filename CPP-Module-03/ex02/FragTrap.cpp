#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other._name) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " ask a high fives" << std::endl;
}
