#include "philo.h"

int	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo -> dinner_info -> print);
	philo -> print = 1;
	if (death(philo))
		return (1);
	printf("%li %li %s\n", current_time(), philo -> guest_number + 1, state);
	philo -> print = 0;
	pthread_mutex_unlock(&philo -> dinner_info -> print);
	return (0);
}