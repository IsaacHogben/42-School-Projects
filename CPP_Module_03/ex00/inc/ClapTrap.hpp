#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string Name;
		int HitPoints;
		int EnergyPoints;
		int AttackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &src);

		void Attack(const std::string& target);
		void TakeDamage(unsigned int amount);
		void BeRepaired(unsigned int amount);

		//test class
		void Status();
};