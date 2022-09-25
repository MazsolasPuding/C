#include <stdio.h>
#include <stdlib.h>


void readMatrix(num){

    char* ptr = (char*)malloc(num * sizeof(char));

    int l = 0, r = 0, i;
    int lineIndex = 0, rowIndex= 0;
    float value, largest;

    FILE *fp;
    fp = fopen("D://Coding/C/parhuzamosHomeWorkOne/matrix.txt", "r");


    while(fgets(ptr, num+5, fp) != NULL) {
//        printf("%s", ptr);
        char *token = strtok(ptr, " ");
        int flag = 0;
        r = 0;
        while(token != NULL){
            value = atof(token);
            token = strtok(NULL, " ");
            if(value > largest || (l==0 && r==0)){
                rowIndex = r;
                largest = value;
                flag++;
            }
            r++;
        }
        if(flag > 0){
            lineIndex = l;
        }
        l++;
    }

    printf("\nLine index: %d", lineIndex);
    printf("\nRow index: %d", rowIndex);
    printf("\nThe largest number: %f", largest);
    fclose(fp);
}

int main() {
    int num;
    printf("Enter number of columns:");
    scanf("%d",&num);
    printf("\n");

    readMatrix(num*20);
    sleep(5);
    return 0;
}
