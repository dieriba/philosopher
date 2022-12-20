#include "philo.h"

void	free_struct(t_info *dinner_info)
{
	if (dinner_info -> philosophers)
		free(dinner_info -> philosophers);
	if (dinner_info -> philo_pid)
		free(dinner_info -> philo_pid);
	if (dinner_info -> sem_names)
		ft_free_tab(dinner_info -> sem_names);
	if (dinner_info -> sem_death)
		free(dinner_info -> sem_death);
}

void	close_sems(t_info *dinner_info)
{
	close_sem(dinner_info, dinner_info -> forks);
	close_sem(dinner_info, dinner_info -> keeper);
	close_sem(dinner_info, dinner_info -> print);
	close_sem(dinner_info, dinner_info -> end);
	close_sem(dinner_info, dinner_info -> plate);
	clean_sem_tabs(dinner_info);
}

void	destroy_sems(t_info *dinner_info)
{
	size_t	i;
	char	**tab;

	tab = dinner_info -> sem_names;
	i = -1;
	while (tab[++i])
		destroy_sem(dinner_info, tab[i]);
	destroy_sem(dinner_info, SEM_FORKS);
	destroy_sem(dinner_info, SEM_KEEPER);
	destroy_sem(dinner_info, SEM_PRINT);
	destroy_sem(dinner_info, SEM_END);
	destroy_sem(dinner_info, SEM_PLATE_EATEN);
}

void	clean_struct(t_info *dinner_info, int main)
{
	close_sems(dinner_info);
	if (main)
		destroy_sems(dinner_info);
	free_struct(dinner_info);
}

void	ft_usleep(int time_to_sleep)
{
	int	mod;
	int	to_iter;

	to_iter = 0;
	mod = time_to_sleep % 10;
	to_iter = mod / 10;
	while (to_iter)
	{
		usleep(10);
		to_iter /= 10;
	}
	if (mod)
		usleep(mod);
}