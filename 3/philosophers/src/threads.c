/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:30:12 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/03 14:30:21 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

//pthread imposes strict paramaters on the function
//it must take and return a single void pointer.
//add usleep to every other philo here to reduce randomness.
void	*philo_thread(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		waitfor(1);
	while (!dead(philo))
	{
		philo_do_actions(philo);
	}
	return (pointer);
}

void	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	monitor_thread;
	int			i;

	if (pthread_create(&monitor_thread, NULL, &monitor, program->philos) != 0)
		destroy_all(program, forks, "Monitoring thread creation error");
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_thread,
				&program->philos[i]) != 0)
			destroy_all(program, forks, "Philosopher thread creation error");
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_all(program, forks, "Monitoring thread join error");
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all(program, forks, "Philosopher thread join error");
		i++;
	}
}
