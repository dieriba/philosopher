#include "philo.h"

void    unlock_mutexes(t_philo *philo)
{
    if (philo -> right_f)
        pthread_mutex_unlock(philo->right);
    if (philo -> left_f)
        pthread_mutex_unlock(philo->left);
    if (philo -> print)
        pthread_mutex_unlock(&philo -> dinner_info -> print);
    if (philo -> keeper_set)
        pthread_mutex_unlock(&philo -> dinner_info -> keeper);
    philo -> print = 0;
    philo -> keeper_set = 0;
    philo -> left_f = 0;
    philo -> right_f = 0;
}