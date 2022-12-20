/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:16:34 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 01:16:34 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	usleep(philo -> time_to_sleep * 1000);
	
	return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	return (0);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
	if (philo -> guest_number % 2)
		usleep(philo -> time_to_sleep * 1000);
	while (1)
	{
		if (takes_forks(philo))
			break ;
		if (eating(philo))
			break ;
		release_forks(philo);
		if (sleeping(philo) || thinking(philo))
			break ;
	}
	unlock_mutexes(philo);
	return (NULL);
}
