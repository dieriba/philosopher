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

int	malloc_struct(t_info *dinner_info)
{
    dinner_info -> philosophers = malloc(sizeof(t_philo) * dinner_info -> guests_numbers);
	if (!dinner_info -> philosophers)
		return (ft_putstr_fd("Sadly, All philosophers were unable to attend the dinner (malloc)\n", 2));
	dinner_info -> forks = malloc(sizeof(pthread_mutex_t) * dinner_info -> guests_numbers);
	if (!dinner_info -> forks)
	{
		free_struct(dinner_info);
		return (ft_putstr_fd("Sadly, All forks could not be set on the table (malloc)\n", 2));
	}
	dinner_info -> death = malloc(sizeof(t_death) * dinner_info -> guests_numbers);
	if (!dinner_info -> death)
	{
		free_struct(dinner_info);
		return (ft_putstr_fd("Sadly, All forks could not be set on the table (malloc)\n", 2));
	}
	return (0);
}