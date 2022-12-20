#include "philo.h"

void	takes_right(t_philo *philo)
{
	lock(philo -> dinner_info, philo -> forks);
	print_state(philo, "takes a fork");
    return (0);
}

void	takes_left(t_philo *philo)
{
	lock(philo -> dinner_info, philo -> forks);
    print_state(philo, "takes a fork");
    return (0);
}

void	takes_forks(t_philo *philo)
{
    if (!(philo -> guest_number % 2))
    {
        takes_left(philo);
        takes_right(philo);
    }
    else
    {
        takes_right(philo);
        takes_left(philo);
    }
    return (0);
}

void	release_forks(t_philo *philo)
{
    unlock(philo -> dinner_info, philo -> forks);
	unlock(philo -> dinner_info, philo -> forks);
}

void	eating(t_philo *philo)
{
    t_info  *dinner_info;

    dinner_info = philo -> dinner_info;
    if (print_state(philo, "is eating"))
        return (1);
    usleep(philo -> time_to_eat * 1000);
    lock(dinner_info, philo -> death_sem);
    gettimeofday(philo -> last_dinner, NULL);
    unlock(dinner_info, philo -> death_sem);
    philo -> eaten_dinner++;
    if (philo -> eaten_dinner == philo -> min_dinner)
    {
        release_forks(philo);
        unlock(dinner_info, philo -> dinner_info -> plate);
    }
}