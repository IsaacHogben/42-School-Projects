/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:55 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/26 12:41:56 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_isnumber(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 5)
	{
		if (i != 5 && argv[i][j] == '-')
			error("Argument that is not meals is negative");
		else
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				error("Arguments not integers");
		}
		i++;
		j = 0;
	}
}

void	check_inputs(int argc, char **argv)
{
	check_isnumber(argv);
	if (atoi(argv[1]) > 200)
		error("Too many philosophers");
	argc = 0;
}
