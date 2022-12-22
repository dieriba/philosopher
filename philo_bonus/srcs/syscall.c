/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:26 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:26 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_info *dinner_info)
{
	if (dinner_info -> philosophers)
		free(dinner_info -> philosophers);
	if (dinner_info -> philo_pid)
		free(dinner_info -> philo_pid);
	if (dinner_info -> sem_names)
		ft_free_tab(dinner_info -> sem_names);
	if (dinner_info -> sem_death)
		free(dinner_info -> sem_death);
}

void	close_sems(t_info *dinner_info)
{
	close_sem(dinner_info, dinner_info -> forks);
	close_sem(dinner_info, dinner_info -> print);
	close_sem(dinner_info, dinner_info -> end);
	close_sem(dinner_info, dinner_info -> plate);
	close_sem(dinner_info, dinner_info -> inform);
	clean_sem_tabs(dinner_info);
}

void	destroy_sems(t_info *dinner_info)
{
	size_t	i;
	char	**tab;

	tab = dinner_info -> sem_names;
	i = -1;
	while (tab[++i])
		destroy_sem(dinner_info, tab[i]);
	destroy_sem(dinner_info, SEM_FORKS);
	destroy_sem(dinner_info, SEM_PRINT);
	destroy_sem(dinner_info, SEM_END);
	destroy_sem(dinner_info, SEM_PLATE_EATEN);
	destroy_sem(dinner_info, SEM_INFORM);
	destroy_sem(dinner_info, SEM_END_FIRST);
}

void	clean_struct(t_info *dinner_info, int main)
{
	close_sems(dinner_info);
	if (main)
		destroy_sems(dinner_info);
	clear_process(dinner_info);
	free_struct(dinner_info);
}

void	ft_usleep(long time_to_sleep)
{
	long	begin;

	begin = current_time();
	while (current_time() - begin < time_to_sleep)
		usleep(10);
}
