#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_RAND_SIZE 100
#define INDEX 4095

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Expected 1 argument, given %d arguments\n", argc - 1);
        exit(1);
    }

    int arr_size = atoi(argv[1]);
    int *arr = malloc(sizeof(int) * arr_size);
    int i;
    time_t t = clock();
    srand(time(NULL));

    for (i = 0; i < arr_size; i++)
    {
        arr[i] = (rand() % (MAX_RAND_SIZE));
    }

    t = clock() - t;
    printf("Filled array in %f seconds \n", (double)t / CLOCKS_PER_SEC);

    t = clock();

    printf("array accessed is %d and value is %d\n", INDEX, arr[INDEX]);

    t = clock() - t;

    printf("Accessing took %f seconds", (double)t / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}
