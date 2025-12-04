/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:55 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/26 12:41:56 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (!(argc == 6 || argc == 5))
		error("Wrong Number of Arguments");
	check_inputs(argc, argv);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(&program, philos, forks, argv);
	create_threads(&program, forks);
	destroy_all(&program, forks, "END");
}
