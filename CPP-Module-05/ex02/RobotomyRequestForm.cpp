#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): Form(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	_target = other._target;
	setSigned(other.isSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

	if (!isSigned())
		throw Form::NotSignedException();
	if (!canExecute(executor))
		throw Form::GradeTooLowException("grade must be upper");

	if (std::rand() % 2)
		std::cout << "brr" << std::endl << _target << " has been robotomized" << std::endl << executor.getName() << " executed " << getName() << std::endl;
	else
		std::cout << _target << " hasn't been robotomized" << std::endl;

}
