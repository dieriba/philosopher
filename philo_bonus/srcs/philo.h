/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoure <dtoure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:43:06 by dtoure            #+#    #+#             */
/*   Updated: 2022/12/22 02:43:06 by dtoure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define SEM_FORKS "/sem_forks"
# define SEM_INFORM "/sem_inform"
# define SEM_PRINT "/sem_print"
# define SEM_DEATH "/sem_death_"
# define SEM_END "/sem_end"
# define SEM_PLATE_EATEN "/sem_phil_plate_eaten"
# define SEM_END_FIRST "/sem_end_first"

typedef struct t_info	t_info;
typedef struct t_sem	t_sem;
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
	int				guests_numbers;
	int				time_to_sleep;
	int				time_to_die;
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
	sem_t			*end;
	sem_t			*inform;
	sem_t			**sem_death;
	pid_t			*philo_pid;
	sem_t			*warn_end;
	pthread_t		watchers;
	int				guests_numbers;
	long			begin;
	int				min_dinner;
	int				end_;
	int				plates;
	int				leaved_guests;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				keeper_set;
	char			**sem_names;
	t_sem			*sem;
}	t_info;

typedef struct t_sem
{
	sem_t	*forks;
	sem_t	*keeper;
	sem_t	*print;
	sem_t	*plate;
	sem_t	*end;
	sem_t	*inform;
	sem_t	**sem_death;
}	t_sem;

int		str_is_only_digit(int argc, char **argv);
int		ft_isdigit(char c);
int		ft_putstr_fd(char *str, int fd);
int		ft_nblen(int n);
char	**ft_free_tab(char **tab);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
long	ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

void	print_and_exit(t_info *dinner_info, char *err_msg, int code);
void	*watchers_phil(void *args);
void	free_struct(t_info *dinner_info);
void	routine(t_philo *philo);
void	close_sem(t_info *dinner_info, sem_t *sem);
void	destroy_sem(t_info *dinner_info, char *name);
void	init_semaphores(t_info *dinner_info);
void	unlock(t_info *dinner_info, sem_t *sem);
void	lock(t_info *dinner_info, sem_t *sem);
void	ft_usleep(long time_to_sleep);
void	create_sem(t_info *dinner_info, sem_t **sem,
			char *name, unsigned int val);
void	clean_sem_tabs(t_info *dinner_info);
void	clean_struct(t_info *dinner_info, int main);
void	initialization(t_info *dinner_info, int argc, char **argv);
void	lets_phil_in(t_info *dinner_info, t_philo *philo);
void	*watch(void *args);
void	release_forks(t_philo *philo);
void	forking(t_info *dinner_info);
void	clear_process(t_info *dinner_info);

void	eating(t_philo *philo);
void	takes_forks(t_philo *philo);
void	print_state(t_philo *philo, char *state);
void	lets_phil_in(t_info *dinner_info, t_philo *philo);

long	current_time_death(void);
long	formated_time(long time);
long	convert_to_ms(struct timeval last_dinner);
long	current_time(void);
#endif