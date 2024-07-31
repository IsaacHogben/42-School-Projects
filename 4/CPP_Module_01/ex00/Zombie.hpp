#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <sstream>
#include <iostream>

class Zombie
{
private:
	std::string Name;
public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
