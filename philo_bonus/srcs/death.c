/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:42:50 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 05:23:10 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	has_died(t_philo *philo)
{
	t_info	*dinner_info;
	long	time;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, philo -> death_sem);
	time = current_time() - convert_to_ms(philo -> last_dinner);
	unlock(dinner_info, philo -> death_sem);
	if (time >= dinner_info -> time_to_die)
	{
		lock(dinner_info, dinner_info -> print);
		printf("%011li %i died\n",
			formated_time(dinner_info -> begin), philo -> guest_number + 1);
		unlock(dinner_info, dinner_info -> warn_end);
		unlock(dinner_info, dinner_info -> end);
		return (1);
	}
	return (0);
}

void	*watchers_phil(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (has_died(philo))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
