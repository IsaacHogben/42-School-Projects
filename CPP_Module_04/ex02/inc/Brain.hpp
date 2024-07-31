#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);

		virtual ~Brain();

		Brain &operator=(const Brain &src);

		const std::string GetIdea(size_t i)const;
		void SetIdea(size_t i, std::string idea);
};