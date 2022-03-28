/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:04 by grubin            #+#    #+#             */
/*   Updated: 2022/03/28 11:59:21 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
        if(ft_init_struct(argv, &philo) == 0
            || ft_init_threads(&philo, &params, tab_philo) == 0)
        {
            ft_free(&philo);
            return (0);
        }
       printf("nbeat = %d\n", tab_philo[0].nb_of_eat);
    }
    while (1)
    {
        // verifier que si les philo sont pas mort
        
       // if (tab_philo[1].nb_of_eat == 0)
          //  break ;
    }
    ft_free(&philo);
    return (0);
}