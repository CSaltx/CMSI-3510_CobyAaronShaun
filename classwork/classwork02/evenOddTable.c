#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
    {
        perror("Must include 2 arguments");
        exit(1);
    }
    int high = atoi(argv[2]), i = atoi(argv[1]);
    int even = 0, odd = 0, sum = 0;
    bool isEven;
    printf("%4s %4s %9s\n", "i", "i*i", "Even/Odd");
    for (; i <= high; ++i)
    {
        isEven = i * i % 2 == 0;
        even += isEven ? 1 : 0;
        odd += !isEven ? 1 : 0;
        char *evenOdd = (isEven ? "EVEN" : "ODD");
        printf("%4d %4d %9s\n", i, i * i, evenOdd);
        sum += i * i;
    }
    printf("Even: %d\nOdd: %d\n", even, odd);
    printf("Sum of Squares = %d\n", sum);
    return 0;
}