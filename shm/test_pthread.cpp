#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

namespace { //=================================================================

int sum = 0;

void *runner(void* param)
{
    int upper = atoi((const char*)param);

    sum = 0;

    for (int i=1; i<upper; i++)
        sum += i;

    pthread_exit(0);
}

void calcSum(char* argv[])
{
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);

    pthread_join(tid, NULL);

    printf("[%lu] sum : %d\n", tid, sum);
}

} //===========================================================================

void test_pthread(int argc, char* argv[])
{
    calcSum(argv);
}