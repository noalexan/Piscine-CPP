#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(std::string);
		const std::string &getType() const;
		void setType(std::string);
};

#endif
