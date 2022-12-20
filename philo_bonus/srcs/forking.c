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
    clean_struct(dinner_info);
}

void    forking(t_info *dinner_info)
{
    int     i;
    t_philo *philo;
    pid_t   pid_ret;
    (void)philo;
    i = -1;
    while (++i < dinner_info -> guests_numbers)
    {   
        pid_ret = fork();
        if (pid_ret < 0)
            print_and_exit(dinner_info, "Error occured (fork())\n", 1);
        philo = &dinner_info -> philosophers[i];
        if (pid_ret == 0)
            break ;
        dinner_info -> philo_pid[i] = pid_ret;
    }
    /*if (pid_ret == 0)
        lets_phil_in(dinner_info, philo);
    else
        end_dinner(dinner_info);*/
}