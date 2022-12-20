/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:23:35 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 01:23:59 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long	convert_ts_to_ms(t_death *death)
{
	long	ms;
	long	us;

	ms = (death -> last_dinner.tv_sec) * 1000;
	us = (death -> last_dinner.tv_usec) / 1000;
	return (ms + us);
}
