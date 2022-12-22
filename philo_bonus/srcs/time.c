/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:31 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 18:14:58 by dtoure           ###   ########.fr       */
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
	return ((last_dinner.tv_sec) * 1e6 + last_dinner.tv_usec);
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
