#include <stdio.h>
#include <stdlib.h>

int switch_func()
{
    char grade = 'B';

    switch(grade){
    case 'A':
        printf("You did Greate");
        break;
    case 'B':
        printf("You did Alright");
        break;
    case 'C':
        printf("You did Poorly");
        break;
    case 'D':
        printf("You did Very Bad");
        break;
    case 'F':
        printf("You failed the test");
        break;
    default :
        printf("Invalid Grade");
    }

    return 0;
}
