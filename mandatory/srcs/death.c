int phil_is_dead(t_philo *phil)
{
    if (!phil -> is_dead && !phil -> dinner_info -> num_of_dead_phil)
        return (0);
    if (phil -> right_f)
        pthread_mutex_unlock(phil->right);
    if (phil -> left_f)
        pthread_mutex_unlock(phil->left);
    return (1);
}

void    watchers_phil(void *args)
{
	t_info	*dinner_info;
    int		i;

	i = 0;
	dinner_info = (t_info *)args;
    struct timeval now;
    while (1)
    {
        
    }
    printf("Exited\n");
    return (NULL);
}