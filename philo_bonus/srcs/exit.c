#include "philo.h"

void    print_and_exit(t_info *dinner_info, char *err_msg, int code)
{
    ft_putstr_fd(err_msg, 2);
    if (dinner_info)
        free_struct(dinner_info);
    exit(code);
}

void    clear_process(t_info *dinner_info)
{
    int     i;
    pid_t   *tab;

    tab = dinner_info -> philo_pid;
    i = -1;
    while (++i < dinner_info -> guests_numbers)
        kill(tab[i], SIGTERM);
}