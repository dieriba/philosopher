# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <sys/time.h>
# include "../../libft/libft.h"

typedef struct t_philo	t_philo;
typedef struct t_info	t_info;
typedef struct t_death	t_death;
typedef struct t_philo
{
	int				guest_number;
	int				has_eaten_all;
	int				eaten_dinner;
	int				finished_meal;
	int				state;
	int				right_f;
	int				left_f;
	int				is_dead;
    struct timeval	curr_step;
	struct timeval	last_dinner;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	t_info			*dinner_info;
} 	t_philo;

typedef struct t_info
{
	t_philo			*philosophers;
	int				guests_numbers;
	int				plate_eaten;
	int				min_dinner;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				have_eat_all;
	int				num_of_dead_phil;
	int				keeper_set;
	pthread_mutex_t	*forks;
	pthread_mutex_t	keeper;
	pthread_mutex_t	print;
} t_info;

void release_forks(t_philo *philo);

int eating(t_philo *philo);
int takes_forks(t_philo *philo);
void    watchers_phil(void *args);
int sleeping(t_philo *philo);
int thinking(t_philo *philo);
int initialization(t_info *dinner_info, int argc, char **argv);
int start_and_joining_threads(t_info *dinner_info);
int phil_is_dead(t_philo *phil);
