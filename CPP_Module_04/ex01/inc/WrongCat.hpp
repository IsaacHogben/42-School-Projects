#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &WrongCat);
		~WrongCat();
		WrongCat &operator=(const WrongCat &WrongCat);

		void MakeSound()const;
};