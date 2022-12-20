#include "philo.h"


void lets_phil_in(t_info *dinner_info, t_philo *philo)
{
    int i;

    i = philo -> guest_number;
    gettimeofday(&philo -> last_dinner, NULL);
    philo -> death_sem = dinner_info -> sem_death[i];
    if (pthread_create(&philo -> watcher, NULL, watchers_phil, philo))
        print_and_exit(dinner_info, "Failed thread creation\n", 1);
    routine(philo);
    if (philo -> eaten_dinner == philo -> min_dinner)
    {
        if (pthread_detach(philo -> watcher))
            print_and_exit(dinner_info, "Failled to detach thrad", 1):
    }
    else
    {   
        (pthread_join(philo -> watcher, NULL))
        print_and_exit(dinner_info, "Failed joining thread\n", 1);
    }
    clean_struct(dinner_info, 0);
    exit(0);
}

void    *watch(void * args)
{
    t_info  *dinner_info;

    dinner_info = (t_info *)dinner_info;
    while (1)
    {
        
    }
    return (NULL);
}