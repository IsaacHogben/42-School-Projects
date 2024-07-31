/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:04:42 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/12 13:05:40 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void ShowOptions()
{
	std::cout << "<---------------ADD,------------------------>" << std::endl;
	std::cout << "<------------------SEARCH,------------------>" << std::endl;
	std::cout << "<-------------OR--------EXIT.--------------->" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "                   ";
}

int	main()
{
	Phonebook phonebook;
	//Contact contact;

	std::cout << "<-----------This is the phonebook----------->" << std::endl;
	std::cout << "<---------Why dont you do something--------->" << std::endl;
	ShowOptions();
	std::string cmd;
	while (1)
	{
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.Add();
		else if (cmd == "SEARCH")
			phonebook.Search();
		else if (cmd == "EXIT")
			break;
		else if (cmd == "OR")
			break;
		else
			std::cout << "<----------UNKOWN-CMD---TRY----------------->" << std::endl;
		ShowOptions();
	}
}
