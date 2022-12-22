/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:31 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 04:01:14 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long	convert_to_ms(struct timeval last_dinner)
{
	long	ms;
	long	us;

	ms = (last_dinner.tv_sec) * 1000;
	us = (last_dinner.tv_usec) / 1000;
	return (ms + us);
}

long	current_time_death(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1e6) + (now.tv_usec));
}

long	formated_time(long time)
{
	return (current_time() - time);
}
