/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:05:35 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/26 16:05:43 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

void	init_params(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		philo->num_of_times_to_eat = ft_atoi(argv[5]);
		if (philo->num_of_times_to_eat < 1)
			philo->num_of_times_to_eat = -1;
	}
	else
		philo->num_of_times_to_eat = -1;
}

void	init_philos(t_program *program, t_philo *philos, pthread_mutex_t *forks,
	char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].dead = &program->dead_flag;
		init_params(&philos[i], argv);
		philos[i].last_meal = get_current_time();
		philos[i].start_time = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].r_fork = &forks[i];
		if (i + 1 != philos[i].num_of_philos)
			philos[i].l_fork = &forks[i + 1];
		else
			philos[i].l_fork = &forks[0];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_philos)
{
	while (--num_philos >= 0)
		pthread_mutex_init(&forks[num_philos], NULL);
}
