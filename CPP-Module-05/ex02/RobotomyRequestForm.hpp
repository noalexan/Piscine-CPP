#pragma once

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{

	private:
		std::string	_target;

	public:
		RobotomyRequestForm(const std::string &);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		virtual ~RobotomyRequestForm();

		void execute(const Bureaucrat &) const;

};
