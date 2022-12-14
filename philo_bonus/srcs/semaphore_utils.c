/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:18 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/23 18:31:07 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(t_info *dinner_info, sem_t *sem)
{
	if (sem_wait(sem))
		print_and_exit(dinner_info, SEM_WAIT_ERR, 1);
}

void	unlock(t_info *dinner_info, sem_t *sem)
{
	if (sem_post(sem))
		print_and_exit(dinner_info, SEM_POST_ERR, 1);
}

void	destroy_sem(t_info *dinner_info, char *name)
{
	if (sem_unlink(name) < 0)
		print_and_exit(dinner_info, SEM_UNL_ERR, 1);
}

void	close_sem(t_info *dinner_info, sem_t *sem)
{
	if (sem_close(sem) < 0)
		print_and_exit(dinner_info, SEM_CL_ERR, 1);
}

void	clean_sem_tabs(t_info *dinner_info)
{
	size_t	i;
	sem_t	**sem;

	sem = dinner_info -> sem_death;
	i = -1;
	while (sem[++i])
		close_sem(dinner_info, sem[i]);
}
