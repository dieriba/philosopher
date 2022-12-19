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

void	destroy_sem(t_info *dinner_info)
{
	if (sem_unlink(dinner_info -> forks) < 0)
		print_and_exit("Semaphore unlink failed\n", 1);
	if (sem_unlink(dinner_info -> keeper) < 0)
		print_and_exit("Semaphore unlink failed\n", 1);
	if (sem_unlink(dinner_info -> print) < 0)
		print_and_exit("Semaphore unlink failed\n", 1);
	if (sem_unlink(dinner_info -> error) < 0)
		print_and_exit("Semaphore unlink failed\n", 1);
}

void	close_sem(t_info *dinner_info)
{
	if (sem_close(dinner_info -> forks) < 0)
		print_and_exit("Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> keeper) < 0)
		print_and_exit("Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> print) < 0)
		print_and_exit("Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> error) < 0)
		print_and_exit("Semaphore close failled\n", 1);
}

void	init_semaphores(t_info *dinner_info)
{
	dinner_info -> forks = sem_open(SEM_FORKS, O_CREAT, 0644, dinner_info -> philosophers);
	if (dinner_info -> forks == SEM_FAILED)
		print_and_exit("semaphore (syscall failed)\n", 1);
	dinner_info -> keeper = sem_open(SEM_KEEPER, O_CREAT, 0644, 1);
	if (dinner_info -> keeper == SEM_FAILED)
		print_and_exit("semaphore (syscall failed)\n", 1);
	dinner_info -> print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (dinner_info -> print == SEM_FAILED)
		print_and_exit("semaphore (syscall failed)\n", 1);
	dinner_info -> error = sem_open(SEM_ERROR, O_CREAT, 0644, 0)
	if (dinner_info -> error == SEM_FAILED)
		print_and_exit("semaphore (syscall failed)\n", 1);
}