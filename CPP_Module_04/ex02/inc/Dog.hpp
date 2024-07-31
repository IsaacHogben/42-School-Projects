#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog &operator=(const Dog &dog);

		void MakeSound()const;

		void GetIdeas(void)const;
		void SetIdea(size_t i, std::string idea);
};