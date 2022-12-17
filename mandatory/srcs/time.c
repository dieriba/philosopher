#include "philo.h"

long int    current_time(void)
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    return (now.tv_sec);
}

// long int    format_time(long time)
// {
//     return (time);
// }