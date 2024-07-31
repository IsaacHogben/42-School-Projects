/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:46:09 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/12 13:46:10 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int		index;
	int		numContacts;
public:
	Phonebook();
	void Add(void);
	void Search(void);
};


#endif

