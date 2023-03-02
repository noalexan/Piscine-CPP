#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	public:
		Form(const std::string, int, int);
		Form(const Form &);
		Form &operator=(const Form &);
		~Form();

		class GradeTooHighException : public std::exception
		{

			private:
				const char *_what;

			public:
				GradeTooHighException();
				GradeTooHighException(const char *);
				GradeTooHighException(const GradeTooHighException &);
				GradeTooHighException &operator=(const GradeTooHighException &);
				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception
		{

			private:
				const char *_what;

			public:
				GradeTooLowException();
				GradeTooLowException(const char *);
				GradeTooLowException(const GradeTooLowException &);
				GradeTooLowException &operator=(const GradeTooLowException &);
				const char *what() const throw();

		};

		std::string getName() const;
		int isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &);

};

std::ostream &operator<<(std::ostream &, const Form &);

#endif

class Form;
