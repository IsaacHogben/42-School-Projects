/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:52:28 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/12 14:52:30 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

//checks inputs are numbers
int	check_args(char **argv, int size)
{
	int	i;

	i = 0;
	while (size + 1 > 0)
	{
		while (argv[size][i] != '\0')
		{
			if ((argv[size][i] < '0' || argv[size][i] > '9')
			&& (argv[size][i] != '-' && argv[size][i] != '+'))
			{
				ft_printf("Error");
				exit (1);
			}
			i++;
		}
		size--;
		i = 0;
	}
	return (0);
}

void	check_values(int size, int *list)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (list[i] == list[j] && i != j)
			{
				ft_printf("Error");
				exit (0);
			}
			j++;
		}
		if (list[i] >= 2147483647 || list[i] <= -2147483648)
		{
			ft_printf("Error");
			exit (0);
		}
		i++;
	}
}
