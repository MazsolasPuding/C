#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * difference(int *a, int *b){
    static int *res;
    res = (int *) malloc(5 * sizeof(int));
    int ind = 0;
    bool flag;

    for (int i = 0; i < 5; i++){
        flag = false;
        for (int j = 0; i < 5; j++){
            if (a[i] == b[j]){
                flag = true;
            }
        }
        if (!flag){
            res[ind] = a[i];
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int *res_a;
    int *res_b;
    int res_total[10];

    res_a = difference(&a, &b);
    res_b = difference(&b, &a);

//    memcpy(res_total, res_a, 5 * sizeof(int));
//    memcpy(res_total + 5, res_b, 5 * sizeof(int));

    for (int i = 0; i < 5; i++){
        printf("%d", a[i]);
    }

    return 0;


//    //Initialize array
//    int arr[] = {1, 2, 3, 4, 5};
//    //Calculate length of array
//    int length = sizeof(arr)/sizeof(arr[0]);
//
//    printf("Elements of given array: \n");
//    //Loop through the array by incrementing value of i
//    for (int i = 0; i < length; i++) {
//        printf("%d ", arr[i]);
//    }

    return 0;
}

