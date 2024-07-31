#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal);
		//Virtual functions are member functions whose behavior 
		// can be overridden in derived classes. 
		virtual ~Animal(); 
		Animal &operator=(const Animal &animal);

		std::string getType(void)const;
		void setType(const std::string &type);

		virtual void MakeSound(void)const;
};