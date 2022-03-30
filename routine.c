/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:02:17 by grubin            #+#    #+#             */
/*   Updated: 2022/03/30 13:00:20 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine_bis(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printf("%6ld %d  has taken a fork left\n", current_time()
		- philo->init_time, philo->index_philo);
	pthread_mutex_lock(philo->fork_right);
	printf("%6ld %d  has taken a fork right\n", current_time()
		- philo->init_time, philo->index_philo);
	printf("%6ld %d  is eating\n", current_time()
		- philo->init_time, philo->index_philo);
	philo->last_meal = current_time();
	sleep_ms(philo->params->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	printf("%6ld %d  is sleeping\n", current_time()
		- philo->init_time, philo->index_philo);
	sleep_ms(philo->params->time_to_sleep);
	printf("%6ld %d  is thinking\n", current_time()
		- philo->init_time, philo->index_philo);
	philo->nb_of_eat--;
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index_philo % 2 == 0)
		usleep (1000);
	while (1)
	{
		if (philo->nb_of_eat == 0)
			break ;
		ft_routine_bis(philo);
	}
	return (0);
}
