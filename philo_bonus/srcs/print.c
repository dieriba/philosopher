#include "philo.h"

int	print_state(t_philo *philo, char *state)
{
	t_info	*dinner_info;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> print);
	philo -> print = 1;
	printf("%li %i %s\n", current_time(), philo -> guest_number + 1, state);
	philo -> print = 0;
	unlock(dinner_info, dinner_info -> print);
	return (0);
}