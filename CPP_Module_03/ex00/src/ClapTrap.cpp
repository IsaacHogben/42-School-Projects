#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor Called" << std::endl;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor Called" << std::endl;
}

void ClapTrap::Attack(const std::string& target)
{
		std::cout << "ClapTrap " << this->Name << " is attacking." << std::endl;
	if (this->EnergyPoints)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " does not have enough energy to attack." << std::endl;
}

void ClapTrap::TakeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " takes " << amount << " damage! " << std::endl;
	this->HitPoints -= amount;
}

void ClapTrap::BeRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->Name << " is attempting repairs." << std::endl;
	if (this->EnergyPoints)
	{
		this->HitPoints += amount;
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->Name << " repairs itself, repairing " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->Name << " does not have enough energy to repair." << std::endl;
}

//test class
void ClapTrap::Status()
{
	std::cout << "ClapTrap '" << this->Name << "' Status:" << std::endl;
	std::cout << "HitPoints: " << this->HitPoints << std::endl;;
	std::cout << "EnergyPoints: " << this->EnergyPoints << std::endl;
}