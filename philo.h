/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:46 by grubin            #+#    #+#             */
/*   Updated: 2022/03/28 11:54:34 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

typedef struct s_params
{
    int             argc;
    int             nb_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    pthread_mutex_t *mutex_philo;
}                   t_params;

typedef struct s_philo
{
    int             nb_of_eat;
    int             init_time;
    int             index_philo;
    pthread_mutex_t *fork_left;
    pthread_mutex_t *fork_right;
    pthread_t       thread_philo;
    t_params        *params;
}                   t_philo;

int                 ft_atoi(const char *str);
int                 ft_init_struct(char **argv, t_philo *philo);
int                 ft_init_threads(t_philo *philo, t_params *params, t_philo *tab_philo);
void                ft_free(t_philo *philo);
void                *ft_routine();

#endif