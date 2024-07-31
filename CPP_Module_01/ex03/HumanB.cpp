#include "HumanB.hpp"

HumanB::~HumanB()
{

}

HumanB::HumanB(std::string name) : name(name)
{

}

void HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
	{
		std::cout << this->name << " attacks without weapon" << std::endl;
	}	
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
