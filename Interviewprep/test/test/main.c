#include <stdio.h>
#include <stdlib.h>

int * sqr_list(int length, int range_min, int range_max){
    static int *sqr;
    sqr = (int *) malloc(length * sizeof(int));
    int ind = 0;

    for(int i = range_min; i < range_max; i++){
        sqr[ind] = i * i;
        ind++;
    }

    return sqr;
}

int main(){
    int *p;
    int length = 100;

    p = sqr_list(length, 20, 120);

    for(int i = 0; i < length; i++){
        printf("p[%d] : %d\n", i, *(p + i));
    }
    return 0;
}
