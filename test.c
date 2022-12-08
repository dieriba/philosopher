#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>
struct t_phil;
typedef struct t_info t_info;
typedef struct t_phil t_phil;

typedef struct t_info
{
    int num_of_phil;
    t_phil *philo;
    int min_dinner;
    pthread_mutex_t *mutex;
    int plate_eaten;
    int num_of_dead_phil;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    pthread_mutex_t t_mut;
} t_info;

typedef struct t_phil
{
    int number;
    int has_eaten_all;
    int finished_meal;
    int is_dead;
    int state;
    int left_f;
    int right_f;
    t_info *data;
    pthread_mutex_t *right;
    pthread_mutex_t *left;
    struct timeval last_dinner;
    struct timeval curr_step;
    pthread_t thread;
} t_phil;
int count = 0;

int phil_is_dead(t_phil *phil)
{
    if (!phil->is_dead)
        return (0);
    if (phil->right_f)
        pthread_mutex_unlock(phil->right);
    if (phil->left_f)
        pthread_mutex_unlock(phil->left);
    return (1);
}

int takes_forks(t_phil *philo)
{
    pthread_mutex_lock(philo->left);
    if (phil_is_dead(philo))
        return (1);
    philo->left_f = 1;
    gettimeofday(&philo->curr_step, NULL);
    printf("%li %i takes a fork\n", philo->curr_step.tv_sec * 1000, philo->number + 1);
    pthread_mutex_lock(philo->right);
    gettimeofday(&philo->curr_step, NULL);
    if (phil_is_dead(philo))
        return (1);
    philo->right_f = 1;
    gettimeofday(&philo->curr_step, NULL);
    printf("%li %i takes a fork\n", philo->curr_step.tv_sec * 1000, philo->number + 1);
    return (0);
}

void sleeping(t_phil *philo)
{
    gettimeofday(&philo->curr_step, NULL);
    printf("%li %i is sleeping\n", philo->curr_step.tv_sec * 1000, philo->number + 1);
    sleep(philo->data->time_to_sleep);
}

void thinking(t_phil *philo)
{
    gettimeofday(&philo->curr_step, NULL);
    printf("%li %i is thinking\n", philo->curr_step.tv_sec * 1000, philo->number + 1);
}

void release_forks(t_phil *philo)
{
    pthread_mutex_unlock(philo->left);
    philo->left_f = 0;
    pthread_mutex_unlock(philo->right);
    philo->right_f = 0;
}

void eating(t_phil *philo)
{
    philo->state = 1;
    gettimeofday(&philo->last_dinner, NULL);
    philo->finished_meal++;
    printf("%li %i is eating\n", philo->last_dinner.tv_sec * 1000, philo->number + 1);
    sleep(philo->data->time_to_eat);
    philo->state = 0;
}

void *routine(void *args)
{
    t_phil *philo = (t_phil *)(args);
    int i = philo->number;

    gettimeofday(&philo->last_dinner, 0);
    sleep(1);
    while (!philo->has_eaten_all)
    {
        if (philo->data->num_of_dead_phil && !philo->data->min_dinner)
            break;
        if (takes_forks(philo))
            break;
        pthread_mutex_lock(&philo->data->t_mut);
        if (philo->data->num_of_dead_phil && !philo->data->min_dinner)
            break;
        if (phil_is_dead(philo))
            break;
        eating(philo);
        if (philo->finished_meal == philo->data->min_dinner)
        {
            philo->data->plate_eaten++;
            philo->has_eaten_all = 1;
        }
        pthread_mutex_unlock(&philo->data->t_mut);
        release_forks(philo);
        if (philo->data->num_of_dead_phil && !philo->data->min_dinner)
            break;
        if (philo->has_eaten_all)
            break;
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}

void *watchers_phil(void *args)
{
    t_info *data = (t_info *)args;
    int i = 0;
    struct timeval now;
    while (1)
    {
        if (data->plate_eaten == data->num_of_phil)
            break;
        while (i < data->num_of_phil)
        {
            if (!data->philo[i].is_dead)
            {
                gettimeofday(&now, NULL);
                if (((now.tv_sec - (data->philo[i].last_dinner.tv_sec)) >= data->time_to_die) && (data->philo[i].state != 1))
                {
                    printf("%li %i is dead\n", (now.tv_sec * 1000), data->philo[i].number + 1);
                    data->philo[i].is_dead = 1;
                    data->num_of_dead_phil++;
                }
            }
            if (data->philo[i].is_dead && data->num_of_dead_phil && !data->min_dinner)
            {
                printf("UNFORTUNATELY A DEAD HAS OCCURED AMONG OUR FELLOW PHILOSOPHER\n");
                return (NULL);
            }
            i++;
        }
        i = 0;
    }
    return (NULL);
}

int main(int argc, char *argv[])
{
    t_info data;
    pthread_t watchers;

    memset(&data, 0, sizeof(t_info));
    data.num_of_phil = atoi(argv[1]);
    data.min_dinner = atoi(argv[2]);
    data.time_to_eat = atoi(argv[3]);
    data.time_to_die = atoi(argv[4]);
    data.time_to_sleep = atoi(argv[5]);
    t_phil *philo = malloc(sizeof(t_phil) * data.num_of_phil);
    if (!philo)
        return (1);
    pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t) * data.num_of_phil);
    data.mutex = mutex;
    if (!mutex)
    {
        free(philo);
        return (1);
    }
    int i = 0;
    while (i < data.num_of_phil)
    {
        pthread_mutex_init(&data.mutex[i], NULL);
        i++;
    }
    printf("Number : %i\n", data.num_of_phil);
    pthread_mutex_init(&data.t_mut, NULL);
    i = 0;
    while (i < data.num_of_phil)
    {
        philo[i].number = i;
        philo[i].has_eaten_all = 0;
        philo[i].data = &data;
        philo[i].is_dead = 0;
        philo[i].right = &data.mutex[i];
        if (i == (data.num_of_phil - 1))
            philo[i].left = &data.mutex[0];
        else
            philo[i].left = &data.mutex[i + 1];
        i++;
    }
    data.philo = philo;
    i = 0;
    while (i < data.num_of_phil)
    {
        pthread_create(&data.philo[i].thread, NULL, routine, &data.philo[i]);
        i++;
    }
    pthread_create(&watchers, NULL, watchers_phil, &data);
    i = 0;
    while (i < data.num_of_phil)
    {
        pthread_join(data.philo[i].thread, NULL);
        i++;
    }
    pthread_join(watchers, NULL);
    printf("Dinner eaten : %i\n", data.plate_eaten);
    i = 0;
    while (i < data.num_of_phil)
    {
        pthread_mutex_destroy(&data.mutex[i]);
        i++;
    }
    pthread_mutex_destroy(&data.t_mut);
}