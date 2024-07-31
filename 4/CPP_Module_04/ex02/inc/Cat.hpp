#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat &operator=(const Cat &cat);

		void MakeSound()const;

		void GetIdeas(void)const;
		void SetIdea(size_t i, std::string idea);
};