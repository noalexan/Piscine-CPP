#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(Intern const &) {
	return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(std::string const &name, std::string const &target) {
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int e = -1;

	for (int i = 0; i < 4; i++)
		if (forms[i] == name)
			e = i;

	switch (e) {

		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);

		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);

		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);

		default:
			std::cerr << "Unable to create form" << std::endl;
			return NULL;

	}
}
