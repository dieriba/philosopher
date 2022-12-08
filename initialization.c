#include "common.h"

static int initialize_philo(t_info *dinner_info)
{
    int i;

    i = -1;

    while (++i < dinner_info->guests_numbers)
    {
        dinner_info->philosophers[i].guest_number = i;
        dinner_info->philosophers[i].eaten_dinner = 0;
        dinner_info->philosophers[i].is_dead = 0;
        dinner_info->philosophers[i].left = &forks[i];
        if ((i + 1) != dinner_info->guests_numbers)
            dinner_info->philosophers[i].right = &forks[i + 1];
        else
            dinner_info->philosophers[i].right = &forks[0];
    }
    return (EXIT_SUCCESS);
}

static int initialize_dinner(t_info *dinner_info)
{
    int i;

    i = -1;
    dinner_info->have_eat_all = 0;
    dinner_info->philosophers = malloc(sizeof(t_philosopher) * dinner_info->guests_numbers);
    if (!dinner_info->philosophers)
        return (ft_putstr_fd("Sadly, All philosophers were unable to attend the dinner (malloc)\n", 2));
    dinner_info->forks = malloc(sizeof(pthread_mutex_t) * dinner_info->guests_numbers);
    if (!dinner_info->forks)
    {
        free(dinner_info->philosophers);
        return (ft_putstr_fd("Sadly, All forks could not be set on the table (malloc)\n", 2));
    }
    while (++i < dinner_info->guests_numbers)
    {
        if (pthread_mutex_init(&dinner_info->forks[i]))
            return (ft_putstr_fd("Sadly, We were not able to initialize all of the mutexes (mutex)\n", 2));
    }
}

static int check_error(t_info *dinner_info, t_philo *philosophers, int args, char **argv)
{

    dinner_info->guests_numbers = ft_atoi(argv[1]);
    dinner_info->time_to_die = ft_atoi(argv[2]);
    dinner_info->time_to_eat = ft_atoi(argv[3]);
    dinner_info->time_to_sleep = ft_atoi(argv[4]);
    if (args > 5)
        dinner_info->min_dinner = ft_atoi(argv[5]);
    if (dinner_info->guests_numbers < 2)
        return (ft_putstr_fd("Philosophers numbers must be superior to 1", 2));
    if (dinner_info->time_to_die < 0)
        return (ft_putstr_fd("Time to die must be a non negative value", 2));
    if (dinner_info->time_to_eat < 0)
        return (ft_putstr_fd("Time to eat must be a non negative value", 2));
    if (dinner_info->time_to_sleep < 0)
        return (ft_putstr_fd("Time to sleep must be a non negative value", 2));
    if (args > 5 && dinner_info->min_dinner <= 0)
        return (ft_putstr_fd("number of eats must be superior or equal to 0", 2));
    return (EXIT_SUCCESS);
}

int initialization(t_info *dinner_info, int args, char **argv)
{
    memset(dinner_info, 0, sizeof(t_info));
    if (check_error(dinner_info, args, argv))
        return (EXIT_FAILURE);
    if (initialize_dinner(dinner_info))
        return (EXIT_FAILURE);
    if (initialize_philo(dinner_info))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}