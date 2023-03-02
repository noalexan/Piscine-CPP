#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): Form(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	_target = other._target;
	setSigned(other.isSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw Form::NotSignedException();
	if (!canExecute(executor))
		throw Form::GradeTooLowException("grade must be upper");

	std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl << executor.getName() << " executed " << getName() << std::endl;
}
