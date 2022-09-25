#include <stdio.h>
#include <stdlib.h>

int read_file() {

    char line[255];
    FILE *fpointer = fopen("matrix.txt", "r");

    fgets(line, 255, fpointer);
    printf("%s", line);

    fclose(fpointer);
    return 0;
}
