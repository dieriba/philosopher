#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

long    second_to_ms(long time)
{
    return (time * 1000);
}

long    micro_to_ms(long time)
{
    return (time / 1000);
}

int main (int argc, char **argv)
{
   
}