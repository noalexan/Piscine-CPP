#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete(this->_brain);
}

void Cat::makeSound() const {
	std::cout << "✨ Un miaou divin ✨" << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}
