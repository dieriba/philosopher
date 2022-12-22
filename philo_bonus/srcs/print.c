/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:13 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:13 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *state)
{
	t_info	*dinner_info;
	long	formated;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> print);
	formated = formated_time(dinner_info -> begin);
	printf("%011li %i %s\n", formated, philo -> guest_number + 1, state);
	unlock(dinner_info, dinner_info -> print);
}
