#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal();
	public:	
		Animal(const Animal &animal);
		virtual ~Animal();
		Animal &operator=(const Animal &animal);

		std::string getType(void)const;
		void setType(const std::string &type);

		//functions as a common interface but leaves implementationt to derived classes.
		//The = 0 is not related to const. It's used in conjunction with virtual to indicate
		//that the function is pure virtual. That means it must be overridden by a sub-class. 
		//Classes containing pure virtual functions are sometimes described as abstract because 
		//they cannot be directly instantiated.
		virtual void MakeSound(void)const = 0;
};