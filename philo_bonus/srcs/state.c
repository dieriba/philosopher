/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:23 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:23 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takes_right(t_philo *philo)
{
	t_info	*dinner_info;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> forks);
	print_state(philo, "takes a fork");
}

void	takes_left(t_philo *philo)
{
	t_info	*dinner_info;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> forks);
	print_state(philo, "takes a fork");
}

void	takes_forks(t_philo *philo)
{
	if (!(philo -> guest_number % 2))
	{
		takes_left(philo);
		takes_right(philo);
	}
	else
	{
		takes_right(philo);
		takes_left(philo);
	}
}

void	release_forks(t_philo *philo)
{
	t_info	*dinner_info;

	dinner_info = philo -> dinner_info;
	unlock(dinner_info, dinner_info -> forks);
	unlock(dinner_info, dinner_info -> forks);
}

void	eating(t_philo *philo)
{
	t_info	*dinner_info;

	dinner_info = philo -> dinner_info;
	print_state(philo, "is eating");
	ft_usleep(philo -> time_to_eat);
	lock(dinner_info, philo -> death_sem);
	gettimeofday(&philo -> last_dinner, NULL);
	unlock(dinner_info, philo -> death_sem);
	philo -> eaten_dinner++;
	if (philo -> eaten_dinner == philo -> min_dinner)
	{
		release_forks(philo);
		unlock(dinner_info, philo -> dinner_info -> plate);
		unlock(dinner_info, dinner_info -> inform);
		lock(dinner_info, philo -> death_sem);
		lock(dinner_info, philo -> death_sem);
	}
}