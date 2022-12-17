#include "philo.h"

void    *routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
    if (philo -> guest_number)
        usleep(300);
    while (1)
    {
        pthread_mutex_lock(&philo -> dinner_info -> keeper);
        philo -> keeper_set = 1;
        if (phil_is_dead(philo))
            break ;
        philo -> keeper_set = 0;
        pthread_mutex_unlock(&philo -> dinner_info -> keeper);
        if (takes_forks(philo))
            break ;
        if (eating(philo))
        {
            unlock_mutexes(philo);
            break ;
        }
        release_forks(philo);
        if (sleeping(philo) || thinking(philo))
            break ;
    }
    unlock_mutexes(philo);
    return (NULL);
}

int start_and_joining_threads(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
    {
        gettimeofday(&dinner_info -> philosophers[i].last_dinner, NULL);
		if (pthread_create(&dinner_info -> philosophers[i].thread, NULL, routine, &dinner_info -> philosophers[i]))
            return (1);
    }
    watchers_phil(dinner_info);
	i = -1;
	while (++i < dinner_info -> guests_numbers  && dinner_info -> guests_numbers > 1)
		if (pthread_join(dinner_info -> philosophers[i].thread, NULL))
            return (1);
    if (dinner_info -> guests_numbers == 1)
    {
        if (pthread_detach(dinner_info -> philosophers[0].thread))
            return (1);
    }
	i = -1;
	while (++i < dinner_info -> guests_numbers && dinner_info -> guests_numbers > 1)
		if (pthread_mutex_destroy(&dinner_info -> forks[i]))
            return (1);
	if (pthread_mutex_destroy(&dinner_info -> keeper))
        return (1);
    return (0);
}