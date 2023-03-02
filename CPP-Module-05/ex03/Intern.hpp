#pragma once

#include <iostream>
#include "Form.hpp"

class Intern
{

	public:
		Intern();
		Intern(Intern const &);
		Intern &operator=(Intern const &);
		virtual ~Intern();

		Form *makeForm(std::string const &, std::string const &);

};
