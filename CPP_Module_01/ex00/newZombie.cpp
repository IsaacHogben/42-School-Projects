#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie *z = new Zombie(name);
	z->announce();
}
