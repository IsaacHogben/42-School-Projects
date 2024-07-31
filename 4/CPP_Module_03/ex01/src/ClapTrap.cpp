#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Constructor Called without name" << std::endl;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) : Name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20)
{
	std::cout << "ClapTrap Constructor Called with name: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor Called" << std::endl;
}

void ClapTrap::Attack(const std::string& target, const std::string& type)
{
	std::cout << type << " " << this->Name << " is attacking." << std::endl;
	if (this->EnergyPoints)
	{
		this->EnergyPoints--;
		std::cout << type << " " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << type << " " << this->Name << " does not have enough energy to attack." << std::endl;
}

void ClapTrap::Attack(const std::string& target)
{
	Attack(target, "ClapTrap");
}

void ClapTrap::TakeDamage(unsigned int amount)
{
	std::cout << this->Name << " takes " << amount << " damage! " << std::endl;
	this->HitPoints -= amount;
}

void ClapTrap::BeRepaired(unsigned int amount)
{
	std::cout << this->Name << " is attempting repairs." << std::endl;
	if (this->EnergyPoints)
	{
		this->HitPoints += amount;
		this->EnergyPoints--;
		std::cout << this->Name << " repairs itself, repairing " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << this->Name << " does not have enough energy to repair." << std::endl;
}

//test class
void ClapTrap::Status()
{
	std::cout << this->Name << "'s Status:" << std::endl;
	std::cout << "HitPoints: " << this->HitPoints << std::endl;;
	std::cout << "EnergyPoints: " << this->EnergyPoints << std::endl;
}