#include "philo.h"

void	print_state(t_philo *philo, char *state)
{
	t_info	*dinner_info;
	int		dead;

	dead = 0;
	dinner_info = philo -> dinner_info;
	lock(dinner_info, dinner_info -> print);
	printf("%li %i %s\n", current_time(), philo -> guest_number + 1, state);
	unlock(dinner_info, dinner_info -> print);
}