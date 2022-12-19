#include "philo.h"

void    print_and_exit(t_info *dinner_info, char *err_msg, int code)
{
    ft_putstr_fd(err_msg, 2);
    if (dinner_info)
        free_struct(dinner_info);
    exit(code);
}