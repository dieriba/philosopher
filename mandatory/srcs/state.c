#include "philo.h"

int takes_right(t_philo *philo)
{
    pthread_mutex_lock(philo -> right);
    philo -> right_f = 1;
    gettimeofday(&philo -> curr_step, NULL);
    pthread_mutex_lock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 1;
    if (phil_is_dead(philo))
        return (1);
    printf("%08li %i takes a fork\n", format_time(philo -> curr_step.tv_usec), philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 0;
    return (0);
}

int takes_left(t_philo *philo)
{
    pthread_mutex_lock(philo -> left);
    philo -> left_f = 1;
    pthread_mutex_lock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 1;
    if (phil_is_dead(philo))
        return (1);
    gettimeofday(&philo -> curr_step, NULL);
    printf("%08li %i takes a fork\n", format_time(philo -> curr_step.tv_usec), philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 0;
    return (0);
}

int takes_forks(t_philo *philo)
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

int sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 1;
    if (phil_is_dead(philo))
            return (1);
    gettimeofday(&philo -> curr_step, NULL);
    printf("%08li %i is sleeping\n", format_time(philo -> curr_step.tv_usec), philo -> guest_number + 1);
    philo -> keeper_set = 0;
    pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    usleep(philo -> dinner_info -> time_to_sleep);
    return (0);
}

int thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 1;
    if (phil_is_dead(philo))
            return (1);
    gettimeofday(&philo -> curr_step, NULL);
    printf("%08li %i is thinking\n", format_time(philo -> curr_step.tv_usec), philo -> guest_number + 1);
    pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 0;
    return (0);
}

void release_forks(t_philo *philo)
{
    if (philo -> left_f)
        pthread_mutex_unlock(philo -> left);
    philo -> left_f = 0;
    if (philo -> right_f)
        pthread_mutex_unlock(philo -> right);
    philo -> right_f = 0;
}

int eating(t_philo *philo)
{
    philo -> finished_meal++;
    pthread_mutex_lock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 1;
    if (phil_is_dead(philo))
        return (1);
    gettimeofday(&philo -> curr_step, NULL);
    printf("%08li %i is eating\n",  format_time(philo -> curr_step.tv_usec), philo -> guest_number + 1);
    gettimeofday(&philo -> last_dinner, NULL);
    if (phil_is_dead(philo))
        return (1);
    philo -> eaten_dinner++;
    if (philo -> eaten_dinner == philo -> dinner_info -> min_dinner)
    {
        philo -> dinner_info -> leaved_guests++;
        return (1);
    }
    pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    philo -> keeper_set = 0;
    usleep(philo -> dinner_info -> time_to_eat);
    return (0);
}