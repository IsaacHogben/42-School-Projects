#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <sstream>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA();
		~HumanA();
		HumanA(std::string name, Weapon &weapon);
		void setWeapon(Weapon weapon);
		void attack();
};

#endif
