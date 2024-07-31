#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    // Additional initialization if needed
    std::cout << "FragTrap Constructor Called with name: " << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor Called" << std::endl;
}

void FragTrap::Attack(const std::string& target)
{
    ClapTrap::Attack(target, "FragTrap");
}

void FragTrap::HighFiveGuys()
{
	std::cout << "ScavTrap " << this->Name << " requests a High Five from the other traps." << std::endl;
}