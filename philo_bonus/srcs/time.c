#include "philo.h"

long	current_time(void)
{
    struct timeval	now;

    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long    convert_to_ms(struct timeval last_dinner)
{
    long	ms;
	long	us;

	ms = (last_dinner.tv_sec) * 1000;
	us = (last_dinner.tv_usec) / 1000;
	return (ms + us);
}