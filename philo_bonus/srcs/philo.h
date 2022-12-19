
#ifndef PHILO_H
# define PHILO_H

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
# include "../../libft/libft.h"

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
	sem_t			*death;
	sem_t			*forks;
	sem_t			*keeper;
	sem_t			*print;
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
}	t_info;

void    print_and_exit(t_info *dinner_info, char *err_msg, int code);
void	*watchers_phil(void *args);
void	free_struct(t_info *dinner_info);
void    *routine(void *args);
void	close_sem(t_info *dinner_info);
void	destroy_sem(t_info *dinner_info);
void	init_semaphores(t_info *dinner_info);
void	unlock(t_info *dinner_info, sem_t *sem);
void	lock(t_info *dinner_info, sem_t *sem)


int		eating(t_philo *philo);
int		takes_forks(t_philo *philo);
int		initialization(t_info *dinner_info, int argc, char **argv);
int		start_and_joining_threads(t_info *dinner_info);
int		death(t_philo *philo);
int		print_state(t_philo *philo, char *state);
void    lets_phil_in(t_info *dinner_info, t_philo *philo);

long	convert_ts_to_ms(t_death *death);
long	current_time(void);
#endif