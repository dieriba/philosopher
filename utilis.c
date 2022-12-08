#include "common.h"

int ft_putstr_fd(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
    if (fd == 2)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void print_state_time(t_philosopher *philosopher, char *state)
{
    long long now;

    gettimeofday(&now, NULL);
    printf("%lli %i %s", now.tv_sec, philosopher->guest_number, state);
}

int free_data(void *data)
{
    if (data)
        free(data);
    return (EXIT_FAILURE);
}

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (nptr[i] - '0');
        i++;
    }
    return (res * sign);
}