#include "philo.h"

int	death(t_philo *philo)
{
	pthread_mutex_lock(&philo -> dinner_info -> keeper);
	philo -> keeper_set = 1;
	if (philo -> dinner_info -> num_of_dead_phil)
	{
		unlock_mutexes(philo);
		return (1);
    }
	philo -> keeper_set = 0;
	pthread_mutex_unlock(&philo -> dinner_info -> keeper);
	return (0);
}

int	condition_met(t_info *dinner_info)
{
	if (dinner_info -> num_of_dead_phil )
		return (1);
	pthread_mutex_lock(&dinner_info -> keeper);
	if ((dinner_info -> leaved_guests 
        == dinner_info -> guests_numbers))
    {
        pthread_mutex_unlock(&dinner_info -> keeper);
        return (1);
    }
    pthread_mutex_unlock(&dinner_info -> keeper);
    return (0);
}

int	who_died(t_info *dinner_info, t_death *death)
{
    int		i;
    long	time;
    t_philo	*philo;

    philo = dinner_info -> philosophers;
    i = -1;
    while (++i < dinner_info -> guests_numbers)
    {
        pthread_mutex_lock(&death[i].death);
        time = current_time() - convert_ts_to_ms(&death[i]);
        pthread_mutex_unlock(&death[i].death);
        if (time >= dinner_info -> time_to_die)
        {
            pthread_mutex_lock(&dinner_info -> keeper);
            dinner_info -> num_of_dead_phil = 1;
            pthread_mutex_unlock(&dinner_info -> keeper);
            pthread_mutex_lock(&dinner_info -> print);
	        printf("%li %li died\n", current_time(), philo[i].guest_number + 1);
            pthread_mutex_unlock(&dinner_info -> print);
        }
        if (condition_met(dinner_info))
            return (1);
    }
    return (0);
}

void	*watchers_phil(void *args)
{
    t_info	*dinner_info;

    dinner_info = (t_info *)args;
    while (1)
    {
        if (who_died(dinner_info, dinner_info -> death))
            return (NULL);
    }
    return (NULL);
}