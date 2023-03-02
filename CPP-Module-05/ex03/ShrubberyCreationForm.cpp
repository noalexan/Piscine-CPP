#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): Form(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	_target = other._target;
	setSigned(other.isSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw Form::NotSignedException();
	if (!canExecute(executor))
		throw Form::GradeTooLowException("grade must be upper");

	std::ofstream	out(_target + "_shrubbery");

	out << " 0 " << std::endl;
	out << "000" << std::endl;
	out << " | " << std::endl;
	out << "___" << std::endl;

	std::cout << executor.getName() << " executed " << getName() << std::endl;
}
