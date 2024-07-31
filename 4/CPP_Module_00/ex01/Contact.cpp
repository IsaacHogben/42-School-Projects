/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:53:43 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/12 12:53:46 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{

}

void	Contact::SetContact(int i)
{
	this->id = i;
	std::cout << "First Name: ";
	std::cin >> this->firstName;
	std::cout << "Last Name: ";
	std::cin >> this->lastName;
	std::cout << "Nick Name: ";
	std::cin >> this->nickName;
	std::cout << "Phone Number: ";
	std::cin >> this->phoneNumber;
	std::cout << "Darkest Secret: ";
	std::cin >> this->darkestSecret;
}

void Contact::ShowAll(void)
{
	std::cout << "Contact Number: " << this->id << std::endl;
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nick Name: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

int	Contact::GetId(void)
{
	return (this->id);
}

std::string Contact::GetFirst(void)
{
	return (this->firstName);
}

std::string Contact::GetLast(void)
{
	return (this->lastName);
}

std::string Contact::GetNick(void)
{
	return (this->nickName);
}