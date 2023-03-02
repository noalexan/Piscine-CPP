#pragma once

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{

	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(const std::string &);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		virtual ~ShrubberyCreationForm();

		void execute(const Bureaucrat &) const;

};
