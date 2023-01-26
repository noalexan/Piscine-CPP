#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

	public:
		FragTrap(const std::string);
		FragTrap(const FragTrap &);
		FragTrap&operator=(const FragTrap &);

		~FragTrap();

		void highFivesGuys();

};

#endif
