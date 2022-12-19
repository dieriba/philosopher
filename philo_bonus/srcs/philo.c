#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	dinner_info;
	
	if (argc < 5)
		return (1);
	initialization(&dinner_info, argc, argv);
	free_struct(&dinner_info);
	return (0);
}