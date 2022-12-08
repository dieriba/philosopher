#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

#define ERROR 1
#define SUCCESS 0
typedef struct t_philosopher t_philosopher;
typedef struct t_info t_info;
typedef struct t_philosopher
{
    int guest_number;
    int eaten_dinner;
    int is_dead;
    struct timeval last_dinner;
    pthread_t philosopher;
    pthread_mutex_t *right;
    pthread_mutex_t *left;
    t_info *dinner_info;
} t_philosopher;

typedef struct t_info
{
    int guests_numbers;
    long end_of_dinner;
    int min_dinner;
    int time_to_sleep;
    int time_to_eat;
    int time_to_die;
    int have_eat_all;
    t_philosopher *philosophers;
    pthread_mutex_t *forks;
    pthread_mutex_t keeper;
    pthread_t watcher_philo_state;
} t_info;
int ft_putstr_fd(char *str, int fd);
int initialization(t_info *dinner_info, int args, char **argv);
int start_and_joining_threads(t_info *dinner_info);
void print_state_time(t_philosopher *philosopher, char *state);
