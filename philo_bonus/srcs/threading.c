/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:29 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:29 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lets_phil_in(t_info *dinner_info, t_philo *philo)
{
	int	i;

	i = philo -> guest_number;
	dinner_info -> begin = current_time();
	gettimeofday(&philo -> last_dinner, NULL);
	philo -> death_sem = dinner_info -> sem_death[i];
	if (pthread_create(&philo -> watcher, NULL, watchers_phil, philo))
		print_and_exit(dinner_info, "Failed thread creation\n", 1);
	routine(philo);
	if (philo -> eaten_dinner == philo -> min_dinner)
	{
		if (pthread_detach(philo -> watcher))
			print_and_exit(dinner_info, "Failled to detach thrad", 1);
	}
	else
	{
		if (pthread_join(philo -> watcher, NULL))
			print_and_exit(dinner_info, "Failed joining thread\n", 1);
	}
	clean_struct(dinner_info, 0);
}

void	*watch(void *args)
{
	t_info	*dinner_info;
	int		plate;

	dinner_info = (t_info *)args;
	plate = 0;
	while (1)
	{
		lock(dinner_info, dinner_info -> plate);
		plate++;
		if (plate == dinner_info -> guests_numbers)
			unlock(dinner_info, dinner_info -> end);
		lock(dinner_info, dinner_info -> inform);
		if (dinner_info -> end_)
			return (NULL);
	}
	return (NULL);
}
