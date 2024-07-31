/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:38:39 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/11 15:38:44 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	for (size_t i = 0; i < input.length(); i++)
		input[i] = std::toupper(input[i]);
	std::cout << input << std::endl;
	return (0);
}
