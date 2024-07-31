#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Deconstructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Equals operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->brain = new Brain();
	*this->brain = *src.brain;
	return *this;
}

void Dog::MakeSound()const
{
	std::cout << "The " << this->getType() << " barks." << std::endl;
}

void	Dog::GetIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Dog is: \"" << this->brain->GetIdea(i) << std::endl;
}

void	Dog::SetIdea(size_t i, std::string idea)
{
		this->brain->SetIdea(i, idea);
}