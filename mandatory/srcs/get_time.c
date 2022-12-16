long int    current_time()
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    return (now.tv_sec);
}