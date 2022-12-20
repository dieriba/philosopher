#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	dinner_info;
	
	if (argc < 5)
		return (1);
	initialization(&dinner_info, argc, argv);
	clean_struct(&dinner_info, 1);
	return (0);
}