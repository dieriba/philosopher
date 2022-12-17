#include "philo.h"

static void initialize_philo(t_info *dinner_info)
{
	int i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		dinner_info -> philosophers[i].keeper_set = 0;
		dinner_info -> philosophers[i].leaved = 0;
		dinner_info -> philosophers[i].guest_number = i;
		dinner_info -> philosophers[i].eaten_dinner = 0;
		dinner_info -> philosophers[i].is_dead = 0;
		dinner_info -> philosophers[i].left = &dinner_info -> forks[i];
		dinner_info -> philosophers[i].finished_meal = 0;
		dinner_info -> philosophers[i].has_eaten_all = 0;
		dinner_info -> philosophers[i].dinner_info = dinner_info;
		if ((i + 1) != dinner_info -> guests_numbers)
			dinner_info -> philosophers[i].right = &dinner_info -> forks[i + 1];
		else
			dinner_info -> philosophers[i].right = &dinner_info -> forks[0];
	}
}

static int initialize_dinner(t_info *dinner_info)
{
	int i;

	i = -1;
	dinner_info -> leaved_guests = 0;
	dinner_info -> philosophers = malloc(sizeof(t_philo) * dinner_info -> guests_numbers);
	if (!dinner_info -> philosophers)
		return (ft_putstr_fd("Sadly, All philosophers were unable to attend the dinner (malloc)\n", 2));
	dinner_info -> forks = malloc(sizeof(pthread_mutex_t) * dinner_info -> guests_numbers);
	if (!dinner_info->forks)
	{
		free(dinner_info -> philosophers);
		return (ft_putstr_fd("Sadly, All forks could not be set on the table (malloc)\n", 2));
	}
	while (++i < dinner_info -> guests_numbers)
		if (pthread_mutex_init(&dinner_info -> forks[i], NULL))
			return (ft_putstr_fd("Sadly, We were not able to initialize all of the mutexes (mutex)\n", 2));
	if  (pthread_mutex_init(&dinner_info -> keeper, NULL))
			return (ft_putstr_fd("Sadly, We were not able to initialize all of the mutexes (mutex)\n", 2));
	return(0);
}

static int check_error(t_info *dinner_info, int argc, char **argv)
{
	dinner_info -> num_of_dead_phil = 0;
	dinner_info -> keeper_set = 0;
	dinner_info -> guests_numbers = ft_atoi(argv[1]);
	dinner_info -> time_to_die = ft_atoi(argv[2]) * 1000;
	dinner_info -> time_to_eat = ft_atoi(argv[3]) * 1000;
	dinner_info -> time_to_sleep = ft_atoi(argv[4]) * 1000;
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

int initialization(t_info *dinner_info, int argc, char **argv)
{
	memset(dinner_info, 0, sizeof(t_info));
	if (check_error(dinner_info, argc, argv))
		return (1);
	if (initialize_dinner(dinner_info))
		return (1);
	initialize_philo(dinner_info);
	return (0);
}