#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LIMIT 25

static void *child(void *ignored)
{
    while (1)
    {
        sleep(5);
        printf("Child is running\n");
    }
}

int main()
{
    pthread_t child_thread;
    int code;
    char buffer[MAX_LIMIT];

    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code)
    {
        fprintf(stderr, "Cannot resolve child thread! Execution failed with code %d\n", code);
        return 2;
    }
    printf("Child thread has been created\n");
    printf("Press any key to kill child thread\n");
    fgets(buffer, MAX_LIMIT, stdin);
    code = pthread_cancel(child_thread);
    printf("Child thread has been killed\n");
    return 0;
}
