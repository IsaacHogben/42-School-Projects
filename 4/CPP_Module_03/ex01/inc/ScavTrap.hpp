#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &src);

		void Attack(const std::string& name);
		void GuardGate();
};