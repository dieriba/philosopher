#include "philo.h"

int	has_died(t_info *philo)
{
    t_info* dinner_info;
    int		i;
    long	time;

    i = -1;
    dinner_info = philo -> dinner_info;
    while (++i < dinner_info -> guests_numbers)
    {
        lock(dinner_info, philo -> death_sem);
        time = current_time() - convert_ts_to_ms(philo -> last_dinner);
        unlock(dinner_info, philo -> death_sem);
        if (time >= philo -> time_to_die)
        {
            lock(dinner_info, dinner_info -> print);
	        printf("%li %li died\n", current_time(), philo[i].guest_number + 1);
            unlock(dinner_info, dinner_info -> philo_dead);
            return (1);
        }
    }
    return (0);
}

void	*watchers_phil(void *args)
{
    t_philo	*philo;

    philo = (t_philo *)args;
    while (1)
    {
        if (has_died(philo))
            return (NULL);
        usleep(100);
    }
    return (NULL);
}