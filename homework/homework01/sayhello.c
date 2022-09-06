#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    
    char name[25];

    printf("Enter your name: ");
    gets( name );

    printf("\n\n\t\t\t\t\t\tHello, %s\n\n", name);
    // indenting using tab (\t)
    // newlines using \n
    
    // for extra flair add this instead of a mere "Hello, name."
    // printf( "\n\n\t\t\t\t\t\tHello, my dear fellow. I see your name is %s.\n\n Fun to meet you on this day!", name );

    return 0;

}
