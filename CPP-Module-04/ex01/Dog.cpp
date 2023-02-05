#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete(this->_brain);
}

void Dog::makeSound() const {
	std::cout << "🔥 Un wouf imperial 🔥" << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}
