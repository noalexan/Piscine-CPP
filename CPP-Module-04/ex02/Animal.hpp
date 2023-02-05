#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

	protected:
		std::string _type;

	public:
		Animal();
		Animal(const std::string);
		Animal(const Animal &);
		Animal &operator=(const Animal &);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const = 0;

};

#endif
