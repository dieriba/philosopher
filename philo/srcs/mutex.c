/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:25:24 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 01:29:33 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_mutexes(t_info *dinner_info)
{
	size_t	i;
	size_t	j;

	j = dinner_info -> guests_numbers;
	i = -1;
	while (++i < j && j > 1)
	{
		if (pthread_mutex_destroy(&dinner_info -> forks[i]))
			return (1);
		if (pthread_mutex_destroy(&dinner_info -> death[i].death))
			return (1);
	}
	if (pthread_mutex_destroy(&dinner_info -> print))
		return (1);
	if (pthread_mutex_destroy(&dinner_info -> keeper))
		return (1);
	return (0);
}

int	unlock_mutexes(t_philo *philo)
{
	if (philo -> right_f)
		pthread_mutex_unlock(philo->right);
	if (philo -> left_f)
		pthread_mutex_unlock(philo->left);
	if (philo -> keeper_set)
		pthread_mutex_unlock(&philo -> dinner_info -> keeper);
	if (philo -> print)
		pthread_mutex_unlock(&philo -> dinner_info -> print);
	philo -> keeper_set = 0;
	philo -> left_f = 0;
	philo -> right_f = 0;
	philo -> print = 0;
	return (1);
}

int	initialize_mutexes(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_mutex_init(&dinner_info -> forks[i], NULL))
			return (
				ft_putstr_fd(
					"We were not able to initialize all of the mutexes\n", 2));
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_mutex_init(&dinner_info -> death[i].death, NULL))
			return (
				ft_putstr_fd(
					"We were not able to initialize all of the mutexes\n", 2));
	if (pthread_mutex_init(&dinner_info -> print, NULL))
		return (ft_putstr_fd(
				"We were not able to initialize all of the mutexes\n", 2));
	if (pthread_mutex_init(&dinner_info -> keeper, NULL))
		return (
			ft_putstr_fd(
				"We were not able to initialize all of the mutexes\n", 2));
	return (0);
}
