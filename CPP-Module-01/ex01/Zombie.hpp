#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string);
		~Zombie();
		Zombie* zombieHorde(int, std::string);
		void announce();
	private:
		std::string _name;
};

#endif
