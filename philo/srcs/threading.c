/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:21:43 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 01:21:43 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_info *dinner_info)
{
	size_t	i;
	size_t	j;

	j = dinner_info -> guests_numbers;
	i = -1;
	while (++i < j)
		if (pthread_join(dinner_info -> philosophers[i].thread, NULL))
			return (1);
	if (pthread_join(dinner_info -> watchers, NULL))
		return (1);
	return (0);
}

static int	create_threads(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		if (pthread_create(
				&dinner_info -> philosophers[i].thread,
				NULL, routine, &dinner_info -> philosophers[i]))
			return (1);
	}
	if (pthread_create(
			&dinner_info -> watchers, NULL, watchers_phil, dinner_info))
		return (1);
	return (0);
}

int	start_and_joining_threads(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
		gettimeofday(&dinner_info -> death[i].last_dinner, NULL);
	dinner_info -> begin = current_time();
	if (create_threads(dinner_info) || join_threads(dinner_info))
	{
		free_struct(dinner_info);
		clean_mutexes(dinner_info);
		return (1);
	}
	clean_mutexes(dinner_info);
	return (0);
}
