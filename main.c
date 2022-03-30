/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:04 by grubin            #+#    #+#             */
/*   Updated: 2022/03/30 10:44:14 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_check_routine(t_philo *tab_philo, t_params *params, t_philo *philo)
{
    int i;
    
    while (1)
    {
        i = 0;
        while (i < philo->params->nb_philo)
        {
            
            if (tab_philo[i].nb_of_eat == 0)
                return (0);
            if (current_time() - tab_philo[i].last_meal >= params->time_to_die)
            {
                printf("%6ld %d died\n", current_time()
                    - tab_philo[i].init_time, i);
                return (0);
            }
            i++;
        }  
    }
}

int main(int argc, char **argv)
{
    t_philo philo;
    t_params params;
    t_philo *tab_philo;
    
    tab_philo = NULL;
    params.argc = argc;
    philo.params = &params;
    if (params.argc == 5 || params.argc == 6)
    {
        if(ft_init_struct(argv, &philo) == 1)
            return (0);
        tab_philo = ft_init_threads(&philo, &params);
        if (tab_philo == NULL)
            return (0);
        ft_check_routine(tab_philo, &params, &philo);
    }
    return (0);
}