/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:20 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 05:21:55 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_sem(t_info *dinner_info, sem_t **sem,
	char *name, unsigned int val)
{
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, val);
	if (errno == EEXIST)
	{
		sem_unlink(name);
		*sem = sem_open(name, O_CREAT | O_EXCL, 0644, val);
	}
	if (*sem == SEM_FAILED)
		print_and_exit(dinner_info, "semaphore (syscall failed)\n", 1);
}

void	set_sem_name(t_info *dinner_info)
{
	int		i;
	char	**tab;
	char	*num;

	tab = dinner_info -> sem_names;
	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		num = ft_itoa(i);
		tab[i] = ft_strjoin(SEM_DEATH, num);
		if (!tab[i])
			print_and_exit(
				dinner_info, "Error (malloc)(function : set_sem_name)\n", 2);
		free(num);
	}
}

void	set_sem_tabs(t_info *dinner_info)
{
	int		i;
	sem_t	**sem;
	char	**tab;

	set_sem_name(dinner_info);
	tab = dinner_info -> sem_names;
	sem = dinner_info -> sem_death;
	i = -1;
	while (tab[++i])
		create_sem(dinner_info, &sem[i], tab[i], 1);
}

void	init_semaphores(t_info *dinner_info)
{
	create_sem(dinner_info, &dinner_info -> forks,
		SEM_FORKS, dinner_info -> guests_numbers);
	create_sem(dinner_info, &dinner_info -> print, SEM_PRINT, 1);
	create_sem(dinner_info, &dinner_info -> plate, SEM_PLATE_EATEN, 0);
	create_sem(dinner_info, &dinner_info -> inform, SEM_INFORM, 0);
	create_sem(dinner_info, &dinner_info -> end, SEM_END, 0);
	create_sem(dinner_info, &dinner_info -> warn_end, SEM_END_FIRST, 0);
	set_sem_tabs(dinner_info);
}
