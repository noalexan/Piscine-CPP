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

	protected:
		void setSigned(bool);

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

		class NotSignedException : public std::exception
		{

			private:
				const char *_what;

			public:
				NotSignedException();
				NotSignedException(const NotSignedException &);
				NotSignedException &operator=(const NotSignedException &);
				const char *what() const throw();

		};

		std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool canExecute(const Bureaucrat &) const;
		void beSigned(const Bureaucrat &);
		virtual void execute(const Bureaucrat &) const = 0;

};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
