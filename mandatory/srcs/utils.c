#include "philo.h"

int phil_is_dead(t_philo *phil)
{
    if (!phil->is_dead)
        return (0);
    if (phil->right_f)
        pthread_mutex_unlock(phil->right);
    if (phil->left_f)
        pthread_mutex_unlock(phil->left);
    return (1);
}