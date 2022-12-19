#include "philo.h"

void    wait_for_all_childs(t_info *dinner_info)
{
    int     i;
    pid_t   pid;

    i = -1;
    while (++i < dinner_info -> guests_numbers)
    {
        pid = dinner_info -> philo_pid[i];
        if (waitpid(pid, NULL, 0) < 0)
            print_and_exit(dinner_info, "(waitpid()) error\n", 1);
    }
}

void    end_dinner(t_info *dinner_info)
{
    wait_for_all_childs(dinner_info);
    close_sem(dinner_info);
    destroy_sem(dinner_info);
}

void    forking(t_info *dinner_info)
{
    int     i;
    pid_t   pid_ret;

    i = -1;
    while (++i < dinner_info -> guests_numbers)
    {   
        pid_ret = fork();
        if (pid_ret < 0)
            print_and_exit(dinner_info, "Error occured (fork())\n", 1);
        if (pid_ret == 0)
            break ;
        dinner_info -> philo_pid[i] = pid_ret;
    }
    if (pid_ret == 0)
        lets_phil_in(dinner_info, find_phil(pid_ret));
    else
        end_dinner(dinner_info);
}