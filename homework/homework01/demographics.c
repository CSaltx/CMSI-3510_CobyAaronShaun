#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void)
{
    char name[MAX_SIZE];
    int age;
    int class_year;
    char major[MAX_SIZE];
    float GPA;
    char club[MAX_SIZE];

    printf("Please enter your name: ");
    fgets(name, MAX_SIZE, stdin);
    name[strlen(name) - 1] = '\0';
    printf("Please enter your age: ");
    scanf("%d", &age);
    getchar();
    printf("Please enter your class year: ");
    scanf("%d", &class_year);
    getchar();
    printf("Please enter your major: ");
    fgets(major, MAX_SIZE, stdin);
    major[strlen(major) - 1] = '\0';
    printf("Please enter your GPA: ");
    scanf("%f", &GPA);
    getchar();
    printf("Please enter your club: ");
    fgets(club, MAX_SIZE, stdin);
    club[strlen(club) - 1] = '\0';

    printf("\nYour demographic information: \nName: %s\nAge: %d\nClass Year: %d\nMajor: %s\nGPA: %.2f\nClub: %s\n", name, age, class_year, major, GPA, club);

    return 0;
}
