#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie(std::string _name);
		~Zombie();
		void announce();
		Zombie* newZombie(std::string _name);
		void randomChump(std::string _name);
	private:
		std::string name;
};

#endif
