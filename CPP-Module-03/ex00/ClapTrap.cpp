#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &) {
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energy) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void ClapTrap::takeDamage(unsigned int damage) {
	if (this->_energy) {
		this->_hit -= damage;
		std::cout << "ClapTrap " << this->_name << " loose " << damage << ". He have " << this->_hit << " hit points!" << std::endl;
		this->_energy--;
	}
}

void ClapTrap::beRepaired(unsigned int hit) {
	if (this->_energy) {
		this->_hit += hit;
		std::cout << "ClapTrap " << this->_name << " repaired " << hit << " of his hit points. He have " << this->_hit << " hit points!" << std::endl;
		this->_energy--;
	}
}

