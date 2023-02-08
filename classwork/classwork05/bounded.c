
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mutex = 1;
int full = 7; // maximum of seven messages in buffer
int x = 0;

int myWait(int s)
{
    return (--s);
}

int mySignal(int s)
{
    return (++s);
}

static void *producer(void *ignored)
{
    while (1)
    {
        if (mutex)
        {
            if (!full)
            {
                mutex = myWait(mutex);
                x++;
                mutex = mySignal(mutex);
                printf("\n  Producer consumes item %d", x);
            }
            else
            {
                printf("\n  Buffer is full");
            }
        }

        usleep(50000);
    }
}

static void *consumer(void *ignored)
{
    while (1)
    {
        if (mutex)
        {
            if (!full)
            {
                mutex = myWait(mutex);
                x--;
                mutex = mySignal(mutex);
                printf("\n  Consumer consumes item %d", x);
            }
            else
            {
                printf("\n  Buffer is empty");
            }
        }

        usleep(50000);
    }
}

int main()
{
    int n;
    pthread_t producer_thread;
    pthread_t consumer_thread;
    int code;
    int count = 0;

    code = pthread_create(&producer_thread, NULL, producer, NULL);

    if (code)
    {
        fprintf(stderr, "Cannot resolve child thread! Execution failed with code %d\n", code);
        return 2;
    }

    code = pthread_create(&consumer_thread, NULL, consumer, NULL);

    if (code)
    {
        fprintf(stderr, "Cannot resolve child thread! Execution failed with code %d\n", code);
        return 2;
    }

    while (count < 20)
    {
        printf("  parent is sleeping for one second....\n");
        sleep(1);
        count++;
    }
    printf("......Parent is done.\n\n");

    return 0;
}
