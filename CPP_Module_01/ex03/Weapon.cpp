#include "Weapon.hpp"

Weapon::~Weapon()
{

}

Weapon::Weapon(const std::string &type)
{
	this->setType(type);
}

std::string Weapon::getType() const
{
	return(type);
}

void Weapon::setType(const std::string &_type)
{
	type = _type;
}
