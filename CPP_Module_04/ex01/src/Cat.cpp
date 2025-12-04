#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Equals operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->brain = new Brain();
	*this->brain = *src.brain;
	return *this;
}

void Cat::MakeSound()const
{
	std::cout << "The " << this->getType() << " meows." << std::endl;
}

void	Cat::GetIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->brain->GetIdea(i) << std::endl;
}

void	Cat::SetIdea(size_t i, std::string idea)
{
		this->brain->SetIdea(i, idea);
}