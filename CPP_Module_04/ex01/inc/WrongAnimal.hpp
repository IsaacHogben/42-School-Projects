#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrongAnimal);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

		std::string getType(void)const;
		void setType(const std::string &type);

		void MakeSound()const; //wrong animal make sound is not virtual
};