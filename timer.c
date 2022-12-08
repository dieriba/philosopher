#include <sys/time.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    (void)(argc);
    (void)(argv);
    struct timeval time;
    gettimeofday(&time, NULL);
    long int sec = time.tv_sec;
    printf("Current seconds since epoch 1971: %li\n", time.tv_sec);
}