#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &);
		WrongCat &operator=(const WrongCat &);
		virtual ~WrongCat();

		void makeSound() const;

};

#endif
