#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name) {
	std::cout << this->getName() << ": Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other.getName()), _grade(other.getGrade()) {
	std::cout << this->getName() << ": Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << this->getName() << ": Copy assignator called" << std::endl;
	this->_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->getName() << ": Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Bureaucrat &other) {
	s << other.getName() << ", bureaucrat grade " << other.getGrade();
	return s;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Wrong Grade: Grade must be under or equal to 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Wrong Grade: Grade must be over or equal to 150");
}

Bureaucrat	&Bureaucrat::operator++(int) {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	return *this;
}

Bureaucrat	&Bureaucrat::operator--(int) {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}
