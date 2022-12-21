#include "philo.h"

void	print_state(t_philo *philo, char *state)
{
	t_info	*dinner_info;
	long	formated;

	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> print);
	formated = formated_time(dinner_info -> begin);
	printf("%011li %i %s\n", formated, philo -> guest_number + 1, state);
	unlock(dinner_info, dinner_info -> print);
}