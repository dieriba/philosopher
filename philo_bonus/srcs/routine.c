/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:15 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:15 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo -> time_to_sleep);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	return (0);
}

void	routine(t_philo *philo)
{
	if (philo -> guest_number % 2)
		ft_usleep(philo -> time_to_eat);
	while (1)
	{
		if (philo -> eaten_dinner && philo -> guests_numbers % 2)
			ft_usleep(philo -> time_to_die * 0.3);
		takes_forks(philo);
		eating(philo);
		release_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
}
