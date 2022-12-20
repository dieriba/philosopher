#include "philo.h"

int	has_died(t_philo *philo)
{
    t_info* dinner_info;
    int		i;
    long	time;

    i = -1;
    dinner_info = philo -> dinner_info;
    while (++i < dinner_info -> guests_numbers)
    {
        lock(dinner_info, philo -> death_sem);
        time = current_time() - convert_to_ms(philo -> last_dinner);
        unlock(dinner_info, philo -> death_sem);
        if (time >= dinner_info -> time_to_die)
        {
            lock(dinner_info, dinner_info -> print);
	        printf("%li %i died\n", current_time(), philo[i].guest_number + 1);
            unlock(dinner_info, dinner_info -> end);
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