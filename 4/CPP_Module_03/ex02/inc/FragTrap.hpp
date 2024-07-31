#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap &operator=(const FragTrap &src);

		void Attack(const std::string& name);
		void HighFiveGuys();
};