#include "philo.h"

void	free_struct(t_info *dinner_info)
{
	if (dinner_info -> philosophers)
		free(dinner_info -> philosophers);
	if (dinner_info -> forks)
		free(dinner_info -> forks);
	if (dinner_info -> death)
		free(dinner_info -> death);
	dinner_info -> philosophers = NULL;
	dinner_info -> forks = NULL;
	dinner_info -> death = NULL;
}