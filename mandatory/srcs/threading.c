#include "philo.h"

void    *routine(void *args)
{
	t_philo	*philo;
	t_info  *dinner_info;

	philo = (t_philo *)(args);
    dinner_info = philo -> dinner_info;
    gettimeofday(&dinner_info -> death[philo -> guest_number].timestamps, 0);
    if (philo -> guest_number % 2)
        usleep(10);
    while (!phil_is_dead(philo))
    {
        if (dinner_info -> num_of_dead_phil && !dinner_info -> min_dinner)
            break ;
        if (takes_forks(philo))
            break ;
        if (eating(philo))
            break ;
        release_forks(philo);
        if (philo -> has_eaten_all)
            break ;
        if (sleeping(philo) || thinking(philo))
            break ;
    }
    return (NULL);
}

int start_and_joining_threads(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_create(&dinner_info -> philosophers[i].thread, NULL, routine, &dinner_info -> philosophers[i]) < 0)
            return (1);
    watchers_phil(dinner_info);
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_join(dinner_info -> philosophers[i].thread, NULL) < 0)
            return (1);
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_mutex_destroy(&dinner_info -> forks[i]) < 0)
            return (1);
	if (pthread_mutex_destroy(&dinner_info -> keeper) < 0)
        return (1);
    if (pthread_mutex_destroy(&dinner_info -> print) < 0)
        return (1);
    return (0);
}