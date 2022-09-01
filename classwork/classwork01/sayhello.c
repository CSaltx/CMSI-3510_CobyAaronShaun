#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    char name[25];
    printf("Enter your name: ");
    gets( name );
    printf("HELLO, %s", name);
}