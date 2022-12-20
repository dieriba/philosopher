#include "philo.h"

long	current_time(void)
{
    struct timeval	now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}