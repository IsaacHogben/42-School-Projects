#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

class Replace
{
	private:
		std::string ReplaceLine(std::string buffer, std::string search, std::string replace);
	public:
		Replace();
		Replace(char **argv);
		~Replace();
};

#endif