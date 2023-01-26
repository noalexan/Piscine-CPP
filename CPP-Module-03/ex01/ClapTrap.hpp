#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	protected:
		std::string _name;
		int			_hit;
		int			_energy;
		int			_damage;

	public:
		ClapTrap(const std::string);
		ClapTrap(const ClapTrap &);
		ClapTrap&operator=(const ClapTrap &);

		~ClapTrap();

		void attack(const std::string &);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

};

#endif
