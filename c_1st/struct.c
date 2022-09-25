#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int strucure()
{
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy( student1.name, "Jim");
    strcpy( student1.major, "Buisnes");

    struct Student student2;
    student1.age = 12;
    student1.gpa = 4.5;
    strcpy( student2.name, "Pam");
    strcpy( student2.major, "Art");

    printf("%s", student2.name);

    return 0;
}
