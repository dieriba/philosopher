#include "philo.h"






void	print_struct(t_info *dinner_info)
{
	int	i;

	i = -1;
	printf("Numbers of guests : %d\n", dinner_info -> guests_numbers);
	printf("Time to die : %d\n", dinner_info -> time_to_die);
	printf("Time to eat : %d\n", dinner_info -> time_to_eat);
	printf("Time to sleep : %d\n", dinner_info -> time_to_sleep);
	printf("Number of max dinner per guests : %d\n", dinner_info -> min_dinner);
	printf("Plate eaten : %d\n", dinner_info -> plate_eaten);
	printf("Have eat all : %d\n", dinner_info -> have_eat_all);
	printf("Number of dead phil : %d", dinner_info -> num_of_dead_phil);

	printf("\n");
	while (++i < dinner_info -> guests_numbers)
	{
		printf("Guest number : %d\n", dinner_info -> philosophers[i].guest_number + 1);
		printf("Philosopher state : %d\n", dinner_info -> philosophers[i].state);
		printf("Philosopher is dead : %d\n", dinner_info -> philosophers[i].is_dead);
		printf("Philosopher has eaten all : %d\n", dinner_info -> philosophers[i].has_eaten_all);
		printf("Philosopher eaten dinner : %d\n", dinner_info -> philosophers[i].eaten_dinner);
		printf("Philosopher finished meals : %d\n", dinner_info -> philosophers[i].finished_meal);
	}
}










int	main(int argc, char **argv)
{
	t_info	dinner_info;
	if (argc < 5)
		return (1);
	if (initialization(&dinner_info, argc, argv))
		return (1);
	if (start_and_joining_threads(&dinner_info))
		return (1);
	/* print_struct(&dinner_info); */
	printf("A total of %d were eaten\n", dinner_info.plate_eaten);
	free(dinner_info.philosophers);
	free(dinner_info.forks);
	return (0);
}