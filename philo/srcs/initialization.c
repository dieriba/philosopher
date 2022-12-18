#include "philo.h"

static void	init_struct(t_info *dinner_info, char **argv)
{
	dinner_info -> num_of_dead_phil = 0;
	dinner_info -> keeper_set = 0;
	dinner_info -> guests_numbers = ft_atoi(argv[1]);
	dinner_info -> time_to_die = ft_atoi(argv[2]);
	dinner_info -> time_to_eat = ft_atoi(argv[3]);
	dinner_info -> time_to_sleep = ft_atoi(argv[4]);
	dinner_info -> leaved_guests = 0;
}

static void	initialize_philo(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		dinner_info -> death[i].dead = 0;
		dinner_info -> philosophers[i].keeper_set = 0;
		dinner_info -> philosophers[i].left_f = 0;
		dinner_info -> philosophers[i].right_f = 0;
		dinner_info -> philosophers[i].leaved = 0;
		dinner_info -> philosophers[i].guest_number = i;
		dinner_info -> philosophers[i].time_to_eat = dinner_info -> time_to_eat;
		dinner_info -> philosophers[i].time_to_sleep = dinner_info -> time_to_sleep;
		dinner_info -> philosophers[i].min_dinner = dinner_info -> min_dinner;
		dinner_info -> philosophers[i].death = &dinner_info -> death[i];
		dinner_info -> philosophers[i].eaten_dinner = 0;
		dinner_info -> philosophers[i].left = &dinner_info -> forks[i];
		dinner_info -> philosophers[i].dinner_info = dinner_info;
		if ((i + 1) != dinner_info -> guests_numbers)
			dinner_info -> philosophers[i].right = &dinner_info -> forks[i + 1];
		else
			dinner_info -> philosophers[i].right = &dinner_info -> forks[0];
	}
}

static int	initialize_dinner(t_info *dinner_info)
{
	malloc_struct(dinner_info);
	if (initialize_mutexes(dinner_info))
		return (1);
	return(0);
}

static int	check_error(t_info *dinner_info, int argc, char **argv)
{
	if (argc > 5)
		dinner_info -> min_dinner = ft_atoi(argv[5]);
	else
		dinner_info -> min_dinner = 0;
	if (dinner_info -> guests_numbers < 1)
		return (ft_putstr_fd("Philosophers numbers must be greater or equal to 1", 1));
	if (dinner_info -> time_to_die < 0)
		return (ft_putstr_fd("Time to die must be a non negative value", 1));
	if (dinner_info -> time_to_eat < 0)
		return (ft_putstr_fd("Time to eat must be a non negative value", 1));
	if (dinner_info -> time_to_sleep < 0)
		return (ft_putstr_fd("Time to sleep must be a non negative value", 1));
	if (argc > 5 && dinner_info -> min_dinner <= 0)
		return (ft_putstr_fd("number of eats must be superior or equal to 0", 1));
	return (0);
}



int	initialization(t_info *dinner_info, int argc, char **argv)
{
	memset(dinner_info, 0, sizeof(t_info));
	init_struct(dinner_info, argv);
	if (check_error(dinner_info, argc, argv))
		return (1);
	if (initialize_dinner(dinner_info))
	{
		free_struct(dinner_info);
		return (1);
	}
	initialize_philo(dinner_info);
	return (0);
}