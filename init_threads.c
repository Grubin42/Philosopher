/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:02:12 by grubin            #+#    #+#             */
/*   Updated: 2022/03/28 10:59:58 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_mutex(t_params *params)
{
    int i;
    int err;
    
    i = 0;    
    params->mutex_philo = malloc(params->nb_philo * sizeof(pthread_t));
    if (!params->mutex_philo)
        return (0);
    while (i < params->nb_philo)
    {
        err = pthread_mutex_init(&params->mutex_philo[i], NULL);
        if (err!=0)
            return (0);
        i++;
    }
    return (1);
}

int ft_init_forks(t_philo *tab_philo, t_philo *philo)
{
    if (philo->index_philo == philo->params->nb_philo - 1)
    {
        tab_philo[philo->index_philo].fork_left = &philo->params->mutex_philo[philo->index_philo];
        tab_philo[philo->index_philo].fork_right = &philo->params->mutex_philo[0];       
    }
    else
    {
        tab_philo[philo->index_philo].fork_left = &philo->params->mutex_philo[philo->index_philo];
        tab_philo[philo->index_philo].fork_right = &philo->params->mutex_philo[philo->index_philo + 1];
    }
    return(1);
}

int ft_init_threads(t_philo *philo, t_params *params, t_philo *tab_philo)
{
    int err;

    philo->index_philo = 0;
    tab_philo = malloc(philo->params->nb_philo * sizeof(t_philo));
    if (!tab_philo)
        return (0);
    if (ft_init_mutex(params) == 0)
        return (0);
        // stocker gettiemofday dans une variable
    while (philo->index_philo < philo->params->nb_philo)
    {
        tab_philo[philo->index_philo].index_philo = philo->index_philo;
        tab_philo[philo->index_philo].params = params;
        ft_init_forks(tab_philo, philo);
        err = pthread_create(&philo->thread_philo, NULL, &ft_routine, &tab_philo[philo->index_philo]);
        if (err != 0)
            return (0);
        tab_philo[philo->index_philo].thread_philo = philo->thread_philo;
        philo->index_philo++;
    }
    free(tab_philo);
    return (1);
}