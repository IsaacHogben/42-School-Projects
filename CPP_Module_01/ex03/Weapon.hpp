#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <sstream>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		//Weapon();
		Weapon(const std::string &type);
		~Weapon();
		std::string getType() const;
		void setType(const std::string &type);
};

#endif
