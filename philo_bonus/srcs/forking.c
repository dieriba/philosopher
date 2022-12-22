/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:42:56 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:42:56 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_all_childs(t_info *dinner_info)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		pid = dinner_info -> philo_pid[i];
		if (waitpid(pid, NULL, 0) < 0)
			print_and_exit(dinner_info, "(waitpid()) error\n", 1);
	}
}

void	end_dinner(t_info *dinner_info)
{
	if (pthread_create(&dinner_info -> watchers, NULL, watch, dinner_info))
		print_and_exit(dinner_info, "Failed thread creation\n", 1);
	lock(dinner_info, dinner_info -> end);
	dinner_info -> end_ = 1;
	unlock(dinner_info, dinner_info -> plate);
	unlock(dinner_info, dinner_info -> inform);
	if (pthread_join(dinner_info -> watchers, NULL))
		print_and_exit(dinner_info, "Failed joind thread\n", 1);
	clean_struct(dinner_info, 1);
}

void    forking(t_info *dinner_info)
{
	int		i;
	t_philo	*philo;
	pid_t	pid_ret;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		pid_ret = fork();
		if (pid_ret < 0)
			print_and_exit(dinner_info, "Error occured (fork())\n", 1);
		philo = &dinner_info -> philosophers[i];
		if (pid_ret == 0)
			break ;
		dinner_info -> philo_pid[i] = pid_ret;
	}
	if (pid_ret == 0)
		lets_phil_in(dinner_info, philo);
	else
		end_dinner(dinner_info);
}
