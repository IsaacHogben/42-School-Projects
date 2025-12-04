/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:53:43 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/12 12:53:46 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <sstream>//string
#include <iostream> //cin and cout
#include <iomanip> //use of setw

class Contact
{
private:
	int id;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	void SetContact(int);
	int GetId(void);
	std::string GetFirst(void);
	std::string GetLast(void);
	std::string GetNick(void);
	void ShowAll();
};


#endif

