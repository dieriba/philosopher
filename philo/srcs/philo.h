/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:38:51 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/20 00:38:51 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <sys/time.h>

typedef struct t_philo		t_philo;
typedef struct t_info		t_info;
typedef struct t_death		t_death;
typedef struct t_philo
{
	int				keeper_set;
	int				eaten_dinner;
	int				right_f;
	int				left_f;
	int				leaved;
	int				print;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				min_dinner;
	size_t			guest_number;
	int				guests_numbers;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	t_death			*death;
	t_info			*dinner_info;
}	t_philo;

typedef struct t_info
{
	t_philo			*philosophers;
	t_death			*death;
	int				guests_numbers;
	int				min_dinner;
	int				num_of_dead_phil;
	int				leaved_guests;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	long			begin;
	pthread_t		watchers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	keeper;
	pthread_mutex_t	print;
}	t_info;

typedef struct t_death
{
	struct timeval	last_dinner;
	pthread_mutex_t	death;
}	t_death;

long	ft_atoi(const char *nptr);
int		ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *s);
int 	ft_isdigit(char c);

void	release_forks(t_philo *philo);
void	*watchers_phil(void *args);
void	free_struct(t_info *dinner_info);
void	*routine(void *args);
void	ft_usleep(long time_to_sleep);
int		unlock_mutexes(t_philo *philo);
int		eating(t_philo *philo);
int		takes_forks(t_philo *philo);
int		initialization(t_info *dinner_info, int argc, char **argv);
int		start_and_joining_threads(t_info *dinner_info);
int		death(t_philo *philo);
int		print_state(t_philo *philo, char *state);
int		malloc_struct(t_info *dinner_info);
int		clean_mutexes(t_info *dinner_info);
int		initialize_mutexes(t_info *dinner_info);

long	current_time_death(void);
long	formated_time(long time);
long	convert_ts_to_ms(t_death *death);
long	current_time(void);
#endif