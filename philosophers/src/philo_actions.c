/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:27 by ihogben           #+#    #+#             */
/*   Updated: 2023/10/04 16:41:29 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	log_out(philo, "has taken a fork");
	log_out(philo, "has taken a fork");
	log_out(philo, "is eating");
	philo->eating = 1;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	waitfor(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	_sleep(t_philo *philo)
{
	log_out(philo, "is sleeping");
	waitfor(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	log_out(philo, "is thinking");
}

void	philo_do_actions(t_philo *philo)
{
	eat(philo);
	_sleep(philo);
	think(philo);
}
