#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(const Cat &);
		Cat&operator=(const Cat &);
		virtual ~Cat();

		void makeSound() const;

};

#endif
