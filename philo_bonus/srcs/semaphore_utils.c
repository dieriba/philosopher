#include "philo.h"

void	lock(t_info *dinner_info, sem_t *sem)
{
	if (sem_wait(sem))
		print_and_exit(dinner_info, "error with sem_wait\n", 1);
}

void	unlock(t_info *dinner_info, sem_t *sem)
{
	if (sem_post(sem))
		print_and_exit(dinner_info, "error with sem_post\n", 1);
}

void	destroy_sem(t_info *dinner_info, char *name)
{
	if (sem_unlink(name) < 0)
		print_and_exit(dinner_info, "Semaphore unlink failed\n", 1);
}

void	close_sem(t_info *dinner_info, sem_t *sem)
{
	if (sem_close(sem) < 0)
		print_and_exit(dinner_info, "Semaphore close failled\n", 1);
}

void	clean_sem_tabs(t_info *dinner_info)
{
	int	i;
	sem_t	**sem;
	char	**tab;
	(void)tab;
	tab = dinner_info -> sem_names;
	sem = dinner_info -> sem_death;
	i = -1;
	while (++i < dinner_info -> guests_numbers)
		close_sem(dinner_info, sem[i]);
	i = -1;
	while (tab[++i])
		destroy_sem(dinner_info, tab[i]);
}
