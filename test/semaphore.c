# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>           /* For O_* constants */
# include <sys/stat.h>        /* For mode constants */
# include <semaphore.h>
# include<sys/wait.h>

# define SEM_FORKS "/sem_forks"
# define SEM_KEEPER "/sem_keeper"
# define SEM_PRINT "/sem_print"
# define SEM_DEATH "/sem_death"
# define SEM_ERROR "/sem_error"

typedef struct t_philo		t_philo;
typedef struct t_info		t_info;
typedef struct t_philo
{
	pid_t			pid;
	pthread_t		death;
	pthread_t		thread;
    struct timeval	last_dinner;
	int				keeper_set;
	int				eaten_dinner;
	int				right_f;
	int				left_f;
	int				leaved;
	int				print;
	int				is_dead;
	int				time_to_sleep;
	int				time_to_eat;
	int				min_dinner;
	int				guest_number;
	sem_t			*deaths;
	sem_t			*forks;
	sem_t			*keeper;
	sem_t			*prints;
	sem_t			*error;
	t_info			*dinner_info;
}	t_philo;

typedef struct t_info
{
	t_philo			*philosophers;
	int				guests_numbers;
	int				min_dinner;
	int				num_of_dead_phil;
	int				leaved_guests;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				keeper_set;
	pthread_t		watchers;
	sem_t			*forks;
	sem_t			*keeper;
	sem_t			*print;
	sem_t			*error;
	pid_t			*philo_pid;
}	t_info ;

void    print_and_exit(t_info *dinner_info, char *err_msg, int code)
{
    printf("%s" ,err_msg);
    exit(code);
}


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
	if (sem_unlink(SEM_FORKS) < 0)
		print_and_exit(NULL, "Semaphore unlink failed\n", 1);
	if (sem_unlink(SEM_KEEPER) < 0)
		print_and_exit(NULL, "Semaphore unlink failed\n", 1);
	if (sem_unlink(SEM_PRINT) < 0)
		print_and_exit(NULL, "Semaphore unlink failed\n", 1);
	if (sem_unlink(SEM_ERROR) < 0)
		print_and_exit(NULL, "Semaphore unlink failed\n", 1);
}

void	close_sem(t_info *dinner_info)
{
	if (sem_close(dinner_info -> forks) < 0)
		print_and_exit(NULL, "Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> keeper) < 0)
		print_and_exit(NULL, "Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> print) < 0)
		print_and_exit(NULL, "Semaphore close failled\n", 1);
	if (sem_close(dinner_info -> error) < 0)
		print_and_exit(NULL, "Semaphore close failled\n", 1);
}

void	init_semaphores(t_info *dinner_info)
{
	dinner_info -> forks = sem_open(SEM_FORKS, O_CREAT, 0644, dinner_info -> guests_numbers);
	if (dinner_info -> forks == SEM_FAILED)
		print_and_exit(dinner_info, "semaphore (syscall failed)\n", 1);
	dinner_info -> keeper = sem_open(SEM_KEEPER, O_CREAT, 0644, 1);
	if (dinner_info -> keeper == SEM_FAILED)
		print_and_exit(dinner_info, "semaphore (syscall failed)\n", 1);
	dinner_info -> print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (dinner_info -> print == SEM_FAILED)
		print_and_exit(dinner_info, "semaphore (syscall failed)\n", 1);
	dinner_info -> error = sem_open(SEM_ERROR, O_CREAT, 0644, 0);
	if (dinner_info -> error == SEM_FAILED)
		print_and_exit(dinner_info, "semaphore (syscall failed)\n", 1);
}

static void	init_struct(t_info *dinner_info, char **argv)
{
	dinner_info -> num_of_dead_phil = 0;
	dinner_info -> keeper_set = 0;
	dinner_info -> guests_numbers = atoi(argv[1]);
	dinner_info -> time_to_die = atoi(argv[2]);
	dinner_info -> time_to_eat = atoi(argv[3]);
	dinner_info -> time_to_sleep = atoi(argv[4]);
	dinner_info -> leaved_guests = 0;
}

static void	initialize_philo(t_info *dinner_info)
{
	int	i;

	i = -1;
	while (++i < dinner_info -> guests_numbers)
	{
		dinner_info -> philosophers[i].pid = 0;
		dinner_info -> philosophers[i].forks = dinner_info -> forks;
		dinner_info -> philosophers[i].keeper = dinner_info -> keeper;
		dinner_info -> philosophers[i].prints = dinner_info -> print;
		dinner_info -> philosophers[i].keeper_set = 0;
		dinner_info -> philosophers[i].leaved = 0;
		dinner_info -> philosophers[i].is_dead = 0;
		dinner_info -> philosophers[i].guest_number = i;
		dinner_info -> philosophers[i].time_to_eat = dinner_info -> time_to_eat;
		dinner_info -> philosophers[i].time_to_sleep = dinner_info -> time_to_sleep;
		dinner_info -> philosophers[i].min_dinner = dinner_info -> min_dinner;
		dinner_info -> philosophers[i].eaten_dinner = 0;
		dinner_info -> philosophers[i].dinner_info = dinner_info;
	}
}

static void	check_error(t_info *dinner_info, int argc, char **argv)
{
	if (argc > 5)
		dinner_info -> min_dinner = atoi(argv[5]);
	else
		dinner_info -> min_dinner = 0;
	if (dinner_info -> guests_numbers < 1)
		print_and_exit(NULL, "Philosophers numbers must be greater or equal to 1\n", 1);
	if (dinner_info -> time_to_die < 0)
		print_and_exit(NULL, "Time to die must be a non negative value\n", 1);
	if (dinner_info -> time_to_eat < 0)
		print_and_exit(NULL, "Time to eat must be a non negative value\n", 1);
	if (dinner_info -> time_to_sleep < 0)
		print_and_exit(NULL, "Time to sleep must be a non negative value\n", 1);
	if (argc > 5 && dinner_info -> min_dinner <= 0)
		print_and_exit(NULL, "number of eats must be superior or equal to 0\n", 1);
}

void	malloc_struct(t_info *dinner_info)
{
    dinner_info -> philosophers = malloc(sizeof(t_philo) * dinner_info -> guests_numbers);
	if (!dinner_info -> philosophers)
		print_and_exit(dinner_info, "Sadly, All philosophers were unable to attend the dinner (malloc)\n", 2);
	dinner_info -> philo_pid = malloc(sizeof(pid_t) * dinner_info -> guests_numbers);
	if (!dinner_info -> philo_pid)
		print_and_exit(dinner_info, "Sadly, All philosophers were unable to attend the dinner (malloc)\n", 2);
}

void	initialization(t_info *dinner_info, int argc, char **argv)
{
	memset(dinner_info, 0, sizeof(t_info));
	init_struct(dinner_info, argv);
	init_semaphores(dinner_info);
	malloc_struct(dinner_info);
	check_error(dinner_info, argc, argv);
	initialize_philo(dinner_info);
}

void init_sem(sem_t *sem, unsigned int val)
{
	size_t	i;

	i = -1;
	while (++i < val)
		unlock(NULL, sem);
}

void	get_sem_value(t_philo *philo, sem_t *sem)
{
	int val;
	sem_getvalue(sem, &val);
	printf("The semaphore current value for philo : %d is : %d\n", philo ->guest_number, val);
}

int main (int argc, char **argv)
{
    t_info dinner_info;
	sem_t *sem;
	t_philo	*philo;
	memset(&dinner_info, 0, sizeof(t_info));
    initialization(&dinner_info, argc, argv);
	init_sem(dinner_info.forks, dinner_info.guests_numbers);
	init_sem(dinner_info.print, 1);
	init_sem(dinner_info.keeper, 1);

    int	i;
	int pid_ret;
	i = -1;
	while (++i < dinner_info.guests_numbers)
	{
		philo = &dinner_info.philosophers[i];
		pid_ret = fork();
		if (pid_ret < 0)
			return (1);
		if (pid_ret == 0)
			break ;
	}
	if (pid_ret == 0)
	{
		lock(NULL, philo -> keeper);
		philo -> deaths = sem_open(SEM_DEATH, O_CREAT, 0644, 1);
		lock(NULL, philo -> prints);
		get_sem_value(philo, philo -> deaths);
		unlock(NULL, philo -> prints);
		lock(NULL, philo -> forks);
		lock(NULL, philo -> prints);
		printf("Philo : %d takes a fork\n", philo -> guest_number);
		unlock(NULL, philo -> prints);
		lock(NULL, philo -> forks);
		lock(NULL, philo -> prints);
		printf("Philo : %d takes a fork\n", philo -> guest_number);
		unlock(NULL, philo -> prints);
		lock(NULL, philo -> deaths);
		printf("Philo : %d is now eating\n", philo -> guest_number);
		sem_close(philo -> deaths);
		sem_unlink(SEM_DEATH);
		unlock(NULL, philo -> keeper);
	}
	else
	{
		while (wait(NULL) > 0)
			;
	}
}