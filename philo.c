#include "common.h"

void eating(t_philosopher *philosopher)
{
    t_info *dinner_info;

    dinner_info = philosopher.dinner_info;
    while (philosopher->eaten_dinner < dinner_info->min_dinner)
    {
        // check if philo has died
        takes_fork(philosopher);
        pthread_mutex_lock();
        // eating and update eating state;
        pthread_mutex_unlock();
        pthread_mutex_unlock(philosopher->left);
        pthread_mutex_unlock(philosopher->right);
    }
}

void thinking(t_philosopher *philosopher)
{
    print_state_time(philosopher, "is thinking");
}

void sleeping(t_philosopher *philosopher)
{
    print_state_time(philosopher, "is sleeping");
    usleep(philosopher->dinner_info->time_to_sleep * 1000);
}

void takes_fork(t_philosopher *philosopher)
{
    pthread_mutex_lock(philosopher->left);
    print_state_time(philosopher, "has take a fork");
    pthread_mutex_lock(philosopher->right);
    print_state_time(philosopher, "has take a fork");
}