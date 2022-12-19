#include "philo.h"

void	death(t_philo *philo)
{
	lock(philo -> dinner_info, philo -> keeper);
	philo -> keeper_set = 1;
	if (philo -> dinner_info -> num_of_dead_phil)
	{
		unlock_sem(philo);
		exit(1);
    }
	philo -> keeper_set = 0;
	unlock(philo -> dinner_info, philo -> keeper);
}

int	condition_met(t_info *dinner_info)
{
	if (dinner_info -> num_of_dead_phil )
		return (1);
	lock(dinner_info, dinner_info -> keeper);
	if ((dinner_info -> leaved_guests 
        == dinner_info -> guests_numbers))
    {
        unlock(dinner_info, dinner_info -> keeper);
        return (1);
    }
    unlock(dinner_info, dinner_info -> keeper);
    return (0);
}

int	who_died(t_info *philo)
{
    int		i;
    long	time;
    t_philo	*philo;

    philo = dinner_info -> philosophers;
    i = -1;
    while (++i < dinner_info -> guests_numbers)
    {
        lock(philo -> dinner_info, philo -> death);
        time = current_time() - convert_ts_to_ms(&death[i]);
        unlock(philo -> dinner_info, philo -> death);
        if (time >= dinner_info -> time_to_die)
        {
            lock(philo -> dinner_info, dinner_info -> keeper);
            dinner_info -> num_of_dead_phil = 1;
            unlock(philo -> dinner_info, dinner_info -> keeper);
            lock(philo -> dinner_info, dinner_info -> print);
	        printf("%li %li died\n", current_time(), philo[i].guest_number + 1);
			// printf("Philosopher %ld is dead at : %f\n", philo[i].guest_number, ((float)time/1000));
            unlock(philo -> dinner_info, dinner_info -> print);
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