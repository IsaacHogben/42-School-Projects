#include "Animal.hpp"

Animal::Animal() : type("default")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Equals operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void Animal::MakeSound(void)const
{
	std::cout << "This animal does not have a sound." << std::endl;
}

std::string Animal::getType(void)const
{
	return (this->type);
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}
