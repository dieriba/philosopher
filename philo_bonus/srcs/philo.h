
#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/stat.h>   
# include "../../libft/libft.h"

# define SEM_FORKS "/sem_forks"
# define SEM_KEEPER "/sem_keeper"
# define SEM_PRINT "/sem_print"
# define SEM_DEATH "/sem_death_"
# define SEM_PHIL_DEAD "/sem_phil_dead"
# define SEM_PLATE_EATEN "/sem_phil_plate_eaten"

typedef struct t_info	t_info;
typedef struct t_philo
{
	pthread_t		watcher;
    struct timeval	last_dinner;
	int				keeper_set;
	int				eaten_dinner;
	int				right_f;
	int				left_f;
	int				print;
	int				is_dead;
	int				time_to_sleep;
	int				time_to_eat;
	int				min_dinner;
	int				guest_number;
	sem_t			*death_sem;
	t_info			*dinner_info;
}	t_philo;

typedef struct t_info
{
	t_philo			*philosophers;
	sem_t			*forks;
	sem_t			*keeper;
	sem_t			*print;
	sem_t			*plate;
	sem_t			*phil_dead;
	pid_t			*philo_pid;
	pthread_t		watchers;
	int				guests_numbers;
	int				min_dinner;
	int				leaved_guests;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				keeper_set;
	char			**sem_names;
	sem_t			**sem_death;
}	t_info;

void    print_and_exit(t_info *dinner_info, char *err_msg, int code);
void	*watchers_phil(void *args);
void	free_struct(t_info *dinner_info);
void    *routine(void *args);
void	close_sem(t_info *dinner_info, sem_t *sem);
void	destroy_sem(t_info *dinner_info, char *name);
void	init_semaphores(t_info *dinner_info);
void	unlock(t_info *dinner_info, sem_t *sem);
void	lock(t_info *dinner_info, sem_t *sem);
void	ft_usleep(int time_to_sleep);
void	create_sem(t_info *dinner_info, sem_t **sem, char *name, unsigned int val);
void	clean_sem_tabs(t_info *dinner_info);
void	clean_struct(t_info *dinner_info, int main);
void	initialization(t_info *dinner_info, int argc, char **argv);
void lets_phil_in(t_info *dinner_info, t_philo *philo);

void		eating(t_philo *philo);
void		takes_forks(t_philo *philo);
void		death(t_philo *philo);
//int		print_state(t_philo *philo, char *state);
//void    lets_phil_in(t_info *dinner_info, t_philo *philo);

long	current_time(void);
#endif