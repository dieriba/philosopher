#include "philo.h"

















int	main(int argc, char **argv)
{
	t_info	*dinner_info;

	if (initialization(&dinner_info, argc, argv))
		return (1);
	return (0);
}