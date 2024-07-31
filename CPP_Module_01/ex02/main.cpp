#include <iostream>

int	main(void)
{
	std::string string;
	std::string *stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "stringmem: " << &string << std::endl;
	std::cout << "stringPTRmem: " << stringPTR << std::endl;
	std::cout << "stringREFmem: " << &stringREF << std::endl;

	std::cout << "string: " << string << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}
