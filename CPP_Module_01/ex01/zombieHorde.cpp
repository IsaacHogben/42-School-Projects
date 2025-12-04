#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *zombieHorde = new Zombie[N];
	while (N >= 0)
	{
		zombieHorde[N].setName(name);
		N--;
	}
	return(zombieHorde);
}

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie *z = new Zombie(name);
	z->announce();
}
