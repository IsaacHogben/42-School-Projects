#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    // Additional initialization if needed
    std::cout << "ScavTrap Constructor Called with name: " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor Called" << std::endl;
}

void ScavTrap::Attack(const std::string& target)
{
    ClapTrap::Attack(target, "ScavTrap");
}

void ScavTrap::GuardGate()
{
	std::cout << "ScavTrap " << this->Name << " is now in gatekeeper mode." << std::endl;
}