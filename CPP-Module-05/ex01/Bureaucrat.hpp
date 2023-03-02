#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat {

	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat(std::string const &, int);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat &operator=(Bureaucrat const &);
		~Bureaucrat();

		class GradeTooHighException: public std::exception {
			const char * what() const throw();
		};

		class GradeTooLowException: public std::exception {
			const char * what() const throw();
		};

		Bureaucrat	&operator++(int);
		Bureaucrat	&operator--(int);

		std::string getName() const;
		int getGrade() const;
		void signForm(Form &) const;

};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif

class Bureaucrat;
