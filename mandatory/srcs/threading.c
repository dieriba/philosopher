#include "philo.h"

void    routine()
{

}

void    watchers_phil()
{

}

int start_and_joining_threads(t_info *dinner_info)
{
	int	i;

    i = -1;
    while (++i < dinner_info -> guests_numbers)
        pthread_create(dinner_info -> philosophers[i].thread, NULL, routine, &dinner_info -> philosophers[i]);
    pthread_create(dinner_info -> watchers, NULL, watchers_phil, dinner_info);
    i = -1;
    while (++i < dinner_info -> guests_numbers)
        pthread_join(&dinner_info -> philosophers[i].thread, NULL);
    pthread_join(dinner_info -> watchers, NULL);
    i = -1;
    while (++i < dinner_info -> guests_numbers)
        pthread_mutex_destroy(&dinner_info -> forks[i]);
    pthread_mutex_destroy(&dinner_info -> keeper);
}