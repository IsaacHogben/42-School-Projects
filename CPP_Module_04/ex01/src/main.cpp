
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void ) 
{
	int arraySize = 10;
	const Animal	*animals[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl;

	std::cout << "Testing" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal type: " << animals[i]->getType() << std::endl;
		animals[i]->MakeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	std::cout << "Deconstructor chaining test" << std::endl;

	Animal* rightcat = new Cat();
	delete rightcat;	
	WrongAnimal* wrongcat = new WrongCat();
	delete wrongcat;

	std::cout << "Deep copy test" << std::endl;

	Dog *a = new Dog();
	a->SetIdea(0, "dog idea 1");
	a->SetIdea(1, "dog idea 2");
	a->SetIdea(2, "dog idea 3");

	Dog *b = new Dog(*a);
	b->GetIdeas();
	delete b;
}