#include "common.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i++])
        ;
    return (i);
}

int main(int argc, char **argv)
{
    t_info dinner_info;

    if (argc < 5)
    {
        ft_putstr_fd("Usage : ./philosopher <number_of_philosophers> <time_to_die> <time_to_die> <time_to_eat> <time_to_sleep> ((optional) <number_of_times_each_philosopher_must_eat>)\n", 2);
        return (EXIT_FAILURE);
    }
    if (initialization(&dinner_info, argc, argv))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}