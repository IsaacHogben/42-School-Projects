/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:33:56 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/05 13:33:57 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	*simplify_list(int size, int *list)
{
	int	i;
	int	j;
	int	p;
	int	*a;

	a = malloc(sizeof(int) * size + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		p = 1;
		j = 0;
		while (j <= size)
		{
			if (list[i] > list[j])
				p++;
			a[i] = p;
			j++;
		}
		i++;
	}
	free(list);
	return (a);
}

char	**make_list(int argc, char **argv)
{
	char	**a;

	if (argc == 2)
		a = ft_split(argv[1], ' ');
	else
	{
		argv++;
		return (argv);
	}
	return (a);
}

int	get_list_size(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
		i = argc - 2;
	else
	{
		while (argv[i] != NULL)
			i++;
		i--;
	}
	return (i);
}

int	*format_list(t_stackab *s, int argc, char **argv)
{
	int	size;
	int	*a;
	int	i;

	i = 0;
	argv = make_list(argc, argv);
	size = get_list_size(argc, argv);
	check_args(argv, size);
	if (size == 0)
		exit (0);
	s->size = size;
	a = malloc(sizeof(int) * size + 1);
	if (a == NULL)
		return (NULL);
	while (i <= size)
	{
		a[i] = ft_atoi(argv[i]);
		i++;
	}
	check_values(size, a);
	a = simplify_list(size, a);
	return (a);
}
