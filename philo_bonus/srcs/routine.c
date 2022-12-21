#include "philo.h"

int	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
    usleep(philo -> time_to_sleep * 1000);
    return (0);
}

int	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
    return (0);
}

void	routine(t_philo *philo)
{
    if (philo -> guest_number % 2)
        usleep(philo -> time_to_eat * 1000);
    while (1)
    {
        takes_forks(philo);
        if (eating(philo))
            break ;
        release_forks(philo);
        sleeping(philo);
        thinking(philo);
    }
}