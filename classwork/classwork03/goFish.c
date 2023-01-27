#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE INT_FAST16_MAX
#define MIN_SIZE INT_FAST16_MIN

int main(int argc, char *argv[])
{
    char buffer[25];
    int i = 0;
    int inputs[25];
    while (i < 25)
    {
        printf("Enter value here: ");
        int value = atoi(gets(buffer));
        if (value == -9999)
        {
            break;
        }
        else if (value > MAX_SIZE || value < MIN_SIZE)
        {
            perror("Value too large for integer data type!");
        }
        else
        {
            inputs[i] = value;
            ++i;
        }
    }

    int sum = 0;
    int sevens = 0;
    char output[25] = "";

    for (int j = 0; j < i; ++j)
    {
        int value = inputs[j];
        sum += value;
        if (value == 7)
        {
            sevens++;
        }
        sprintf(buffer, "%d", value);
        strncat(output, buffer, 25);
    }
    printf("Sevens is %d\n", sevens);
    printf("Avg is %d\n", sum / i);
    printf("String is %s\n", output);
    return 0;
}
