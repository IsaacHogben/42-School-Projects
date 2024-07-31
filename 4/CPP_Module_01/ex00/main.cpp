#include "Zombie.hpp"

int main()
{
	Zombie *z = newZombie("Clance");
	z->announce();
	randomChump("Grandon");
	delete z;
}
