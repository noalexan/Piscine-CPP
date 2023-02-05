#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string type): _type(type) {
	std::cout << "Animal constructor with type called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destuctor called" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Un bruit au hasard" << std::endl;
}
