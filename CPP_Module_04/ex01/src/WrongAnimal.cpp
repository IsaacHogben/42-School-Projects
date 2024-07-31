#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Equals operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void WrongAnimal::MakeSound(void)const
{
	std::cout << "This WrongAnimal does not have a sound." << std::endl;
}

std::string WrongAnimal::getType(void)const
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}
