#include "philo.h"

long	current_time(void)
{
    struct timeval	now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long	convert_ts_to_ms(t_death *death)
{
    long	ms;
    long	us;

    ms = (death -> last_dinner.tv_sec) * 1000;
    us = (death -> last_dinner.tv_usec) / 1000;
	return (ms + us);
}