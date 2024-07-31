#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
	this->Name = name;
}

void Zombie::announce(void)
{
	std::cout << Name << ": BraiiiiiinnnzzzZ\n";
}

Zombie::~Zombie()
{
	std::cout << Name << " was Destroyed.\n";
}
