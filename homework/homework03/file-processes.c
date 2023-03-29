#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    printf("\aThis code will read important files on your system. Proceed? (Y or N)\n");
    char answer;
    scanf("%c", &answer);

    if (strncmp(&answer, "N", 1) == 0)
    {
        printf("Closing program...");
        exit(2);
    }
    else if (strncmp(&answer, "Y", 1) != 0)
    {
        printf("error reading input, try again...");
        exit(2);
    }
    printf("Continuing with program!\n");
    pid_t returnedValue = fork();
    if (returnedValue < 0)
    {
        perror("error forking");
        return -1;
    }
    else if (returnedValue == 0)
    {
        if (close(STDIN_FILENO) < 0)
        {
            perror("error closing standard input");
            return -1;
        }
        if (open("/etc/passwd", O_RDONLY) < 0)
        {
            perror("error opening /etc/passwd");
            return -1;
        }
        execlp("tr", "tr", "a-z", "A-Z", NULL);
        perror("error executing tr");
        return -1;
    }
    else
    {
        int status;
        if (waitpid(returnedValue, &status, 0) < 0)
        {
            perror("error waiting for child");
            return -1;
        }
        printf("Note the parent still has the old standard output.\n");
    }
    return 0;
}
