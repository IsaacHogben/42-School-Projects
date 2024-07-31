/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:45:59 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/12 13:46:00 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->index = 8;
	this->numContacts = -1;
}

void Phonebook::Add(void)
{
	if (this->index >= 8)
		this->index = 0;
	this->contacts[this->index].SetContact(this->index);
	std::cout << "Contact: " << this->index << " added" << std::endl;
	this->index++;
	if (this->numContacts < 7)
		this->numContacts++;
}

void PrintLine()
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

std::string Concat(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
	return (str);
}

void PrintRow(std::string str1, std::string str2, std::string str3, std::string str4)
{
	PrintLine();
	std::cout << "|";
	Concat(str1);
	std::cout << "|";
	Concat(str2);
	std::cout << "|";
	Concat(str3);
	std::cout << "|";
	Concat(str4);
	std::cout << "|";
	std::cout << std::endl;
}

void Phonebook::Search(void)
{
	PrintRow("Index", "FirstName", "LastName", "NickName");
	int i = 0;
	int index;
	while (i <= this->numContacts)
	{
		PrintRow(std::to_string(this->contacts[i].GetId()),
			this->contacts[i].GetFirst(),
				this->contacts[i].GetLast(),
					this->contacts[i].GetNick());
		i++;
	}
	PrintLine();
	if (this->numContacts < 0)
	{
		std::cout << "<----PHONEBOOK IS EMPTY--------------------->" << std::endl;
		std::cout << "<------------TRY---------------------------->" << std::endl;
	}
	else
	{
		int lowerBound = 0;
		int upperBound = this->numContacts;
		int index = -1;
		std::string input;

		while (true) {
			std::cout << "Enter an index from " << lowerBound << " to " << upperBound << ": ";
			std::cin >> input;

			// Use a stringstream to check if the input is a number
			std::stringstream ss(input);
			if (!(ss >> index) || (ss >> std::ws).peek() != EOF) {
				// If the input is not a valid integer
				std::cout << "Not a valid number. Please try again." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else if (index < lowerBound || index > upperBound) {
				// If the input is outside the specified range
				std::cout << "Input is not within the specified range. Please try again." << std::endl;
			} else {
				// Valid input within the specified range
				break;
			}
		}
		this->contacts[index].ShowAll();
	}
}