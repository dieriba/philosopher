#include "philo.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
    usleep(philo -> time_to_sleep);
    return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
    return (0);
}

void	routine(t_philo *philo)
{
	t_philo	*philo;

	philo = (t_philo *)(args);
    if (philo -> guest_number % 2)
        usleep(philo -> time_to_eat * 0.7);
    while (1)
    {
        takes_forks(philo);
        eating(philo);
        release_forks(philo);
        sleeping(philo);
        thinking(philo);
    }
}

void lets_phil_in(t_info *dinner_info, t_philo *philo)
{
    int i;

    i = philo -> guest_number;
    gettimeofday(&philo -> last_dinner, NULL);
    philo -> death_sem = dinner_info -> sem_death[i];
    if (pthread_create(&philo -> watcher, NULL, watchers_phil, philo))
        print_and_exit(dinner_info, "Failed thread creation\n", 1);
    routine(philo);
    if (pthread_join(philo -> watcher, NULL))
        print_and_exit(dinner_info, "Failed joining thread\n", 1);
}