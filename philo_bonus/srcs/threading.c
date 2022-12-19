#include "philo.h"

void    lets_phil_in(t_info *dinner_info, t_philo *philo)
{
    if (gettimeofday(&philo -> last_dinner, NULL))
        print_and_exit(dinner_info, "syscall time error\n", 1);
    if (pthread_create(&philo -> thread, NULL, routine, &philo))
        print_and_exit(dinner_info, "failed to create threads\n", 1);
    if (pthread_create(&philo -> death, NULL, watchers_phil, &philo))
        print_and_exit(dinner_info, "failed to create threads\n", 1);
    if (pthread_join(philo -> thread, NULL))
        print_and_exit(dinner_info, "Failed to join thread\n", 1);
    if (pthread_join(philo -> death, NULL))
        print_and_exit(dinner_info, "Failed to join thread\n", 1);
}