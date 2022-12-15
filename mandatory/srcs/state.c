#include "philo.h"

int takes_forks(t_philo *philo)
{
    pthread_mutex_lock(philo -> left);
    philo -> left_f = 1;
    gettimeofday(&philo -> curr_step, NULL);
    pthread_mutex_lock(&philo -> dinner_info -> print);
    if (phil_is_dead(philo))
        return (1);
    printf("%li %i takes a fork\n", philo -> curr_step.tv_sec * 1000, philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> print);
    pthread_mutex_lock(philo -> right);
    philo -> right_f = 1;
    gettimeofday(&philo -> curr_step, NULL);
    gettimeofday(&philo -> curr_step, NULL);
    pthread_mutex_lock(&philo -> dinner_info -> print);
    if (phil_is_dead(philo))
        return (1);
    printf("%li %i takes a fork\n", philo->curr_step.tv_sec * 1000, philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> print);
    return (0);
}

int sleeping(t_philo *philo)
{
    if (phil_is_dead(philo))
            return (1);
    gettimeofday(&philo -> curr_step, NULL);
    pthread_mutex_lock(&philo -> dinner_info -> print);
    printf("%li %i is sleeping\n", philo -> curr_step.tv_sec * 1000, philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> print);
    usleep(philo -> dinner_info -> time_to_sleep);
    return (0);
}

int thinking(t_philo *philo)
{
    if (phil_is_dead(philo))
            return (1);
    gettimeofday(&philo -> curr_step, NULL);
    pthread_mutex_lock(&philo -> dinner_info -> print);
    printf("%li %i is thinking\n", philo->curr_step.tv_sec * 1000, philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> print);
    return (0);
}

void release_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo -> left);
    philo -> left_f = 0;
    pthread_mutex_unlock(philo -> right);
    philo -> right_f = 0;
}

int eating(t_philo *philo)
{
    t_info  *dinner_info;

    dinner_info = philo -> dinner_info;
    if (phil_is_dead(philo))
        return (1);
    philo -> state = 1;
    pthread_mutex_lock(&dinner_info -> death[philo -> guest_number].time_p);
    dinner_info -> death[philo -> guest_number].in_use = 1;
    gettimeofday(&dinner_info -> death[philo -> guest_number].timestamps, NULL);
    pthread_mutex_unlock(&dinner_info -> death[philo -> guest_number].time_p);
    dinner_info -> death[philo -> guest_number].in_use = 0;
    philo -> finished_meal++;
    pthread_mutex_lock(&philo -> dinner_info -> print);
    printf("%li %i is eating\n", philo -> dinner_info -> death[philo -> guest_number].timestamps.tv_sec * 1000, philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> print);
    usleep(philo -> dinner_info -> time_to_eat);
    philo -> state = 0;
    return (0);
}