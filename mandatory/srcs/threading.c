#include "philo.h"

void    *routine(void *args)
{
	t_philo	*philo;
	t_info  *dinner_info;

	philo = (t_philo *)(args);
    dinner_info = philo -> dinner_info;
    gettimeofday(&dinner_info -> death[philo -> guest_number].timestamps, 0);
    if (philo -> guest_number % 2)
        sleep(1);
    while (!phil_is_dead(philo))
    {
        if (dinner_info -> num_of_dead_phil && !dinner_info -> min_dinner)
        {
            printf("Philo Number %d breaks from loop\n", philo -> guest_number + 1);
            break ;
        }
        if (takes_forks(philo))
            break ;
        pthread_mutex_lock(&philo -> dinner_info -> keeper);
        if (eating(philo))
            break ;
        if (philo -> finished_meal == philo -> dinner_info -> min_dinner)
        {
            philo -> dinner_info -> plate_eaten++;
            philo -> has_eaten_all = 1;
        }
        pthread_mutex_unlock(&philo-> dinner_info -> keeper);
        release_forks(philo);
        if (philo -> has_eaten_all)
            break ;
        if (sleeping(philo) || thinking(philo))
            break ;
    }
    return (NULL);
}

void    *watchers_phil(void *args)
{
	t_info	*dinner_info;
    int		i;

	i = 0;
	dinner_info = (t_info *)args;
    struct timeval now;
    while (1)
    {
        while (++i < dinner_info -> guests_numbers)
        {
            if (!dinner_info -> philosophers[i].is_dead)
            {
                gettimeofday(&now, NULL);
                if (!dinner_info -> death[i].in_use)
                {
                    if (((now.tv_sec - (dinner_info -> death[i].timestamps.tv_sec)) >= dinner_info -> time_to_die) && (dinner_info -> philosophers[i].state != 1))
                    {
                        printf("%li %i is dead\n", (now.tv_sec * 1000), dinner_info -> philosophers[i].guest_number + 1);
                        dinner_info -> philosophers[i].is_dead = 1;
                        dinner_info -> num_of_dead_phil++;
                    }
                }
            }
            if (dinner_info -> num_of_dead_phil && !dinner_info -> min_dinner)
            {
                printf("UNFORTUNATELY A DEAD HAS OCCURED AMONG OUR FELLOW PHILOSOPHER\n");
                return (NULL);
            }
        }
        if (dinner_info -> min_dinner == dinner_info -> plate_eaten && dinner_info -> min_dinner)
            break ;
        if (dinner_info -> num_of_dead_phil == dinner_info -> guests_numbers)
            return (NULL);
        usleep(dinner_info -> time_to_die);
        i = -1;
    }
    printf("Exited\n");
    return (NULL);
}

int start_and_joining_threads(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_create(&dinner_info -> philosophers[i].thread, NULL, routine, &dinner_info -> philosophers[i]) < 0)
            return (1);
	if (pthread_create(&dinner_info -> watchers, NULL, watchers_phil, dinner_info) < 0)
        return (1);
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_join(dinner_info -> philosophers[i].thread, NULL) < 0)
            return (1);
	if (pthread_join(dinner_info -> watchers, NULL) < 0)
        return (1);
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		if (pthread_mutex_destroy(&dinner_info -> forks[i]) < 0)
            return (1);
	if (pthread_mutex_destroy(&dinner_info -> keeper) < 0)
        return (1);
    if (pthread_mutex_destroy(&dinner_info -> print) < 0)
        return (1);
    return (0);
}