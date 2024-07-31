#include "Harl.hpp"

Harl::Harl()
{
	
}
Harl::~Harl(){}

void Harl::complain(std::string level)
{
	void (Harl::*debug)() = &Harl::debug;
    void (Harl::*info)() = &Harl::info;
    void (Harl::*warning)() = &Harl::warning;
    void (Harl::*error)() = &Harl::error;

	void (Harl::*functions[4])() = { debug, info, warning, error };
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == complains[i])
			(this->*(functions[i]))();
	}
}

void Harl::debug(){
	std::cout << "DEBUG MESSAGE" << std::endl;
}
void Harl::info(){
	std::cout << "INFO MESSAGE" << std::endl;
}
void Harl::warning(){
	std::cout << "WARNING MESSAGE" << std::endl;
}
void Harl::error(){
	std::cout << "ERROR MESSAGE" << std::endl;
}
