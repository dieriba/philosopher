#include "philo.h"

int	takes_right(t_philo *philo)
{
	pthread_mutex_lock(philo -> right);
	philo -> right_f = 1;
	print_state(philo, "takes a fork");
    return (0);
}

int	takes_left(t_philo *philo)
{
    pthread_mutex_lock(philo -> left);
    philo -> left_f = 1;
    print_state(philo, "takes a fork");
    return (0);
}

int	takes_forks(t_philo *philo)
{
    if (!(philo -> guest_number % 2))
    {
        if (takes_left(philo))
            return (1);
        if (takes_right(philo))
            return (1);
    }
    else
    {
        if (takes_right(philo))
            return (1);
        if (takes_left(philo))
            return (1);
    }
    return (0);
}

void	release_forks(t_philo *philo)
{
    if (philo -> left_f)
        pthread_mutex_unlock(philo -> left);
    philo -> left_f = 0;
    if (philo -> right_f)
        pthread_mutex_unlock(philo -> right);
    philo -> right_f = 0;
}

int	eating(t_philo *philo)
{
    t_death *death;
    t_info  *dinner_info;

    dinner_info = philo -> dinner_info;
    death = philo -> death;
    if (print_state(philo, "is eating"))
        return (1);
    usleep(philo -> time_to_eat);
    pthread_mutex_lock(&death -> death);
    gettimeofday(&death -> last_dinner, NULL);
    pthread_mutex_unlock(&death -> death);
    philo -> eaten_dinner++;
    if (philo -> eaten_dinner == philo -> min_dinner)
    {
        pthread_mutex_lock(&dinner_info -> keeper);
        philo -> dinner_info -> leaved_guests++;
        pthread_mutex_unlock(&dinner_info -> keeper);
        return (unlock_mutexes(philo));
    }
    return (0);
}