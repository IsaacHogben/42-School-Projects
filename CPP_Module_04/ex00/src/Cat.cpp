#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Equals operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void Cat::MakeSound()const
{
	std::cout << "The " << this->getType() << " meows." << std::endl;
}
