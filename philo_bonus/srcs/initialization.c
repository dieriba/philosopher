/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:42:59 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:42:59 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_struct(t_info *dinner_info, char **argv)
{
	dinner_info -> guests_numbers = ft_atoi(argv[1]);
	dinner_info -> time_to_die = ft_atoi(argv[2]);
	dinner_info -> time_to_eat = ft_atoi(argv[3]);
	dinner_info -> time_to_sleep = ft_atoi(argv[4]);
	dinner_info -> end_ = 0;
}

static void	initialize_philo(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		dinner_info -> philosophers[i].keeper_set = 0;
		dinner_info -> philosophers[i].guest_number = i;
		dinner_info
			-> philosophers[i].guests_numbers = dinner_info -> guests_numbers;
		dinner_info -> philosophers[i].time_to_die = dinner_info -> time_to_die;
		dinner_info -> philosophers[i].time_to_eat = dinner_info -> time_to_eat;
		dinner_info
			-> philosophers[i].time_to_sleep = dinner_info -> time_to_sleep;
		dinner_info -> philosophers[i].min_dinner = dinner_info -> min_dinner;
		dinner_info -> philosophers[i].eaten_dinner = 0;
		dinner_info -> philosophers[i].dinner_info = dinner_info;
	}
}

static void	check_error(t_info *dinner_info, int argc, char **argv)
{
	if (!str_is_only_digit(argc, argv))
		print_and_exit(NULL, "Only digits are accepted as arguments.\n", 1);
	if (argc > 5)
		dinner_info -> min_dinner = ft_atoi(argv[5]);
	else
		dinner_info -> min_dinner = 0;
	if (dinner_info -> guests_numbers < 1)
		print_and_exit(
			NULL, "Philosophers numbers must be greater or equal to 1.\n", 1);
	if (dinner_info -> time_to_die < 0)
		print_and_exit(NULL, "Time to die must be a non negative value.\n", 1);
	if (dinner_info -> time_to_eat < 0)
		print_and_exit(NULL, "Time to eat must be a non negative value.\n", 1);
	if (dinner_info -> time_to_sleep < 0)
		print_and_exit(NULL, "Time to sleep must be a non negative value.\n", 1);
	if (argc > 5 && dinner_info -> min_dinner <= 0)
		print_and_exit(
			NULL, "number of eats must be superior or equal to 0.\n", 1);
}

void	malloc_struct(t_info *dinner_info)
{
	dinner_info
		-> philosophers = malloc(
			sizeof(t_philo) * dinner_info -> guests_numbers);
	if (!dinner_info -> philosophers)
		print_and_exit(dinner_info, "allocation error occured\n", 2);
	dinner_info
		-> philo_pid = malloc(
			sizeof(pid_t) * dinner_info -> guests_numbers);
	if (!dinner_info -> philo_pid)
		print_and_exit(dinner_info, "allocation error occured\n", 2);
	dinner_info
		-> sem_names = ft_calloc(
			sizeof(char *), (dinner_info -> guests_numbers + 1));
	if (!dinner_info -> sem_names)
		print_and_exit(dinner_info, "allocation error occured\n", 2);
	dinner_info
		-> sem_death = ft_calloc(
			sizeof(sem_t *), (dinner_info -> guests_numbers + 1));
	if (!dinner_info -> sem_death)
		print_and_exit(dinner_info, "allocation error occured\n", 2);
}

void	initialization(t_info *dinner_info, int argc, char **argv)
{
	memset(dinner_info, 0, sizeof(t_info));
	init_struct(dinner_info, argv);
	check_error(dinner_info, argc, argv);
	malloc_struct(dinner_info);
	init_semaphores(dinner_info);
	initialize_philo(dinner_info);
}
