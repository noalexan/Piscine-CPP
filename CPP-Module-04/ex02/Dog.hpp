#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &);
		virtual ~Dog();

		Brain *getBrain() const;
		void makeSound() const;

};

#endif
