#include "Form.hpp"

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute): _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	std::cout << _name << ": Form constructor called" << std::endl;
	_signed = false;
}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
	std::cout << _name << ": Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &) {
	return *this;
}

Form::~Form() {
	std::cout << _name << ": Destructor called" << std::endl;
}

std::string Form::getName() const {
	return _name;
}

int Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _grade_to_sign;
}

int Form::getExecuteGrade() const {
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException("Grade must be upper");
	_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(): _what("Wrong grade") {
}

Form::GradeTooHighException::GradeTooHighException(const char *what): _what(what) {
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &other): _what(other.what()) {
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException &other) {
	_what = other.what();
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return _what;
}

Form::GradeTooLowException::GradeTooLowException(): _what("Wrong grade") {
}

Form::GradeTooLowException::GradeTooLowException(const char *what): _what(what) {
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &other): _what(other.what()) {
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException &other) {
	_what = other.what();
	return *this;
}

const char *Form::GradeTooLowException::what() const throw() {
	return _what;
}

std::ostream &operator<<(std::ostream &s, const Form &other) {
	s << "From: " << other.getName() << " etat: " << ((other.isSigned()) ? "signed" : "not signed") << ", need to be at least " << other.getSignGrade() << " to sign and " << other.getExecuteGrade() << " to execute";
	return s;
}
