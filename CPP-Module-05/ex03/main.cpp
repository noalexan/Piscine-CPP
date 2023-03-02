#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "Form.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	std::srand(std::time(nullptr));

	std::cout << std::endl;

	// Test 1
	{
		ShrubberyCreationForm	a("park");
		Bureaucrat				b("el boss", 1);

		try
		{
			a.beSigned(b);
			a.execute(b);
		}
		catch (std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 2
	{
		RobotomyRequestForm	a("a random thing");
		Bureaucrat			b("pablo", 1);

		try
		{
			b.signForm(a);
			a.execute(b);
			a.execute(b);
			a.execute(b);
			a.execute(b);
		}
		catch (std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 3
	{
		PresidentialPardonForm	a("random guy in the world");
		Bureaucrat				b("jesus", 1);

		try
		{
			a.beSigned(b);
			a.execute(b);
		}
		catch (std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 4
	{
		ShrubberyCreationForm	a("la voie de tram");
		Bureaucrat				b("le maire lol", 1);

		try
		{
			a.beSigned(b);
			b.executeForm(a);
		}
		catch (std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 5
	{
		Intern someRandomIntern;

		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		(void) rrf;
	}

	std::cout << std::endl;

	return 0;
}
