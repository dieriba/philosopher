#include "common.h"

int start_and_joining_threads(t_info *dinner_info)
{
    int i;

    i = -1;
    while (++i < dinner_info->guests_numbers)
        if (pthread_create(&dinner_info->philosophers[i].thread, NULL, dinner, &dinner_info->philosophers[i]))
            return (ft_putstr_fd("Could not create all of the required threads for philosophers (thread)", 2));
    if (pthread_create(&dinner_info->watchers, NULL, watchers, dinner_info))
        return (ft_putstr_fd("Could not create the watchers threads (thread)", 2));
    pthread_detach(&dinner_info->watchers);
    i = -1;
    while (++i < dinner_info->guests_numbers)
        if (pthread_join(dinner_info->philosophers[i].thread, NULL))
            return (ft_putstr_fd("An Errror occured while trying to join all of the threads", 2));
}