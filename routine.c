/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:02:17 by grubin            #+#    #+#             */
/*   Updated: 2022/03/28 11:55:44 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float time_diff(struct timeval *start, struct timeval *end)
{
    // convertir en millisec et ensuite faire la diff.
    return (1000 * end->tv_sec - start->tv_sec) + 1e-3*(end->tv_usec - start->tv_usec);
}

void *ft_routine(void *arg)
{
    t_philo *philo;
    //struct timeval current_time;
    
    philo = (t_philo *)arg;
    while (1)
    {
        if (philo->index_philo % 2 == 1)
            usleep (100);
        pthread_mutex_lock(philo->fork_left);
        printf("philo %d  has taken a fork left\n", philo->index_philo);
        pthread_mutex_lock(philo->fork_right);
        printf("philo %d  has taken a fork right\n", philo->index_philo);
        printf("philo %d  is eating\n", philo->index_philo);
        philo->nb_of_eat--;
        usleep(philo->params->time_to_eat);
        pthread_mutex_unlock(philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);
        // afficher que le philo dort
        printf("philo %d  is sleeping\n", philo->index_philo);
        // usleep de sleep
        usleep(philo->params->time_to_sleep);
        // affiche que le philo pense
        printf("philo %d  is thinking\n", philo->index_philo);
    }
    return (0);
}
        //printf("%ld, philo %d du thread %p\n", current_time - philo->init_time, philo->index_philo, philo->thread_philo);
        //printf("time spent: %0.0f milliesec\n", time_diff(&start, &end));
        //printf("fork_left = %p fork_right = %p ID philo = %d\n", philo->fork_left, philo->fork_right, philo->index_philo);