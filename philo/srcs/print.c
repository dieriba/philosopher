/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:15:48 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 01:15:48 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_philo *philo, char *state)
{
	long	formated;

	pthread_mutex_lock(&philo -> dinner_info -> print);
	philo -> print = 1;
	if (death(philo))
		return (1);
	formated = formated_time(philo -> dinner_info -> begin);
	printf("%09li %li %s\n", formated, philo -> guest_number + 1, state);
	philo -> print = 0;
	pthread_mutex_unlock(&philo -> dinner_info -> print);
	return (0);
}
