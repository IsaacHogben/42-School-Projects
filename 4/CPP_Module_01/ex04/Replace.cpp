/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:31:38 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/24 11:31:41 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(void){}

Replace::Replace(char **argv)
{
	const std::string	filename = argv[1];
	const std::string	search = argv[2];
	const std::string	replace = argv[3];
	std::string			buffer;
	std::ifstream 		infile;
	std::ofstream		outfile;

	infile.open(filename);
	if (!infile.is_open())
	{
		std::perror("Infile error");
		infile.close();
		return;
	}
	std::string outfileName = filename;
	outfile.open(outfileName.append(".replace"), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::perror("Outfile error");
		outfile.close();
		return;
	}
	while (std::getline(infile, buffer))
	{
		buffer = ReplaceLine(buffer, search, replace);
		outfile << buffer;
		if (buffer[buffer.length() != '\0'])
					outfile << std::endl;
	}
}

std::string Replace::ReplaceLine(std::string buffer, std::string search, std::string replace)
{
	int i = 0;
	int j = 0;
	int eraseLength = search.length();
	while (buffer[i])
	{
		if (buffer[i] == search[j])
		{
			while(buffer[i + j] == search[j])
				j++;
			if (j == eraseLength)
			{
				buffer.erase(i, eraseLength);
				buffer.insert(i, replace);				
			}
			j = 0;
		}
		i++;
	}
	return (buffer);
}

Replace::~Replace()
{

}