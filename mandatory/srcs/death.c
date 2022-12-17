#include "philo.h"

int phil_is_dead(t_philo *philo)
{
    if (!philo -> leaved && philo -> is_dead)
    {
        philo -> dinner_info -> leaved_guests++;
        philo -> leaved = 1;
        unlock_mutexes(philo);
        return (1);
    }
    if (philo -> dinner_info -> num_of_dead_phil 
        && !philo -> dinner_info -> min_dinner)
    {
        unlock_mutexes(philo);
        return (1);
    }
    if (!philo -> is_dead)
        return (0);
    return (0);
}

void    watchers_phil(t_info *dinner_info)
{
    int  i;

	i = -1;
    // sleep(1);
    while (1)
    {
        while (++i < dinner_info -> guests_numbers)
        {
            pthread_mutex_lock(&dinner_info -> keeper);
            if (current_time() - dinner_info->philosophers[i].last_dinner.tv_sec >= dinner_info -> time_to_die)
            {
                dinner_info -> num_of_dead_phil = 1;
                printf("%li %d died\n", current_time(), dinner_info -> philosophers[i].guest_number + 1);
                pthread_mutex_unlock(&dinner_info -> keeper);
                return ;
            }
            if (dinner_info -> leaved_guests == dinner_info -> guests_numbers)
            {
                pthread_mutex_unlock(&dinner_info -> keeper);
                return ;
            }
            pthread_mutex_unlock(&dinner_info -> keeper);
        }
        usleep(60);
        i = -1;
    }
}