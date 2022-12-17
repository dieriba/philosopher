#include "philo.h"

long int    current_time(void)
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    return (now.tv_usec);
}

long int    format_time(long time)
{
    return (current_time() - time);
}