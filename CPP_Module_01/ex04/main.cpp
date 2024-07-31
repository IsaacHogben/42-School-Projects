/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:16:56 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/24 11:16:57 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "wrong number of arguments" << std::endl;
	else
	{
		(Replace(argv));
	}
}
