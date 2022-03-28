/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:02:25 by grubin            #+#    #+#             */
/*   Updated: 2022/03/28 11:55:33 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_struct(char **argv, t_philo *philo)
{
    philo->params->nb_philo = ft_atoi(argv[1]);
    philo->params->time_to_die = ft_atoi(argv[2]);
    philo->params->time_to_eat = ft_atoi(argv[3]);
    philo->params->time_to_sleep = ft_atoi(argv[4]);
    if (philo->params->argc == 6)
        philo->nb_of_eat = ft_atoi(argv[5]);
    return (1);
}