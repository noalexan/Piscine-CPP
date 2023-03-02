#pragma once

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{

	private:
		std::string	_target;

	public:
		PresidentialPardonForm(const std::string &);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		virtual ~PresidentialPardonForm();

		void execute(const Bureaucrat &) const;

};
