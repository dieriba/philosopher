#include "philo.h"

int	print_state(t_philo *philo, char *state)
{
	if (sem_wait(philo -> print))
		print_and_exit(philo -> dinner_info, "error with sem wait", 1);
	philo -> print = 1;
	if (death(philo))
		return (1);
	printf("%li %li %s\n", current_time(), philo -> guest_number + 1, state);
	philo -> print = 0;
	if (sem_post(philo -> print))
		print_and_exit(philo -> dinner_info, "error with sem post", 1);
	return (0);
}