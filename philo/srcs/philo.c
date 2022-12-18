#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	dinner_info;
	if (argc < 5)
		return (1);
	if (initialization(&dinner_info, argc, argv))
		return (1);
	if (start_and_joining_threads(&dinner_info))
		return (1);
	free_struct(&dinner_info);
	return (0);
}