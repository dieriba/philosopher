/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:03 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:03 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_sem_value(char *name, sem_t *sem)
{
	int	val;

	sem_getvalue(sem, &val);
	printf("%s value is : %d\n", name, val);
}

void	print_generic_sem_val(t_info dinner_info)
{
	get_sem_value(SEM_FORKS, dinner_info.forks);
	get_sem_value(SEM_INFORM, dinner_info.keeper);
	get_sem_value(SEM_PLATE_EATEN, dinner_info.plate);
	get_sem_value(SEM_PRINT, dinner_info.print);
	get_sem_value(SEM_END, dinner_info.end);
}

void	print_tab_sem_val(sem_t **sem, char **tabs)
{
	size_t	i;

	i = -1;
	while (tabs[++i])
		get_sem_value(tabs[i], sem[i]);
}

int	main(int argc, char **argv)
{
	t_info	dinner_info;
	
	if (argc < 5 || argc > 6)
		return (1);
	initialization(&dinner_info, argc, argv);
	forking(&dinner_info);
	return (0);
}