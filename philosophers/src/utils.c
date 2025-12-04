/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:46:06 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/03 12:46:07 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//changed to log_out because log is alread a function
//will check if philo is dead before logging anything
void	log_out(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead(philo))
		printf("\033[1;37m%zums \033[0m%d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	destroy_all(t_program *program, pthread_mutex_t *forks, char *error_msg)
{
	int	i;

	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (strncmp(error_msg, "END", 4))
		error(error_msg);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error("gettimeofday error");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	waitfor(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
