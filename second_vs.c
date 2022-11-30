#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void check_args(int argc) {
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }
}

void gen_field(char *field, int size)
{
    for (int i = 0; i < size * size; i++) {
        field[i] = '#';
    }
    field[size] = 'S';
    field[2 * size] = 'E';

}

void print_maze(char *field, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", field[i * size + j]);
        }
        printf("\n");

    }
}

void robot_mouse(char *field, int size) {
    bool midle = false;
    int current_pos = size;
    int failed_direction_change = 0;
    while (failed_direction_change <= 2 && !midle) {
        // 0: right traverse, 1: down, 2: left, 3: up
        for (int i = 0; i < 4; i++) {
            while (1) {
                int next_pos = move(field, size, current_pos, i);
                if (next_pos) {
                    current_pos = next_pos;
                    field[current_pos] = ' ';
                    failed_direction_change = 0;
                }
                else {
                    break;
                }
            }
            failed_direction_change++;
            // If the size is even we need to check for the middle 4 pieces of the maze wether they are converted to routes or not.
            if (size % 2 == 0) {
                midle = ((field[((size * size / 2) - (size / 2) - 1)] == ' ') || (field[((size * size / 2) - (size / 2))] == ' ') || (field[((size * size / 2) + (size / 2) - 1)] == ' ') || (field[((size * size / 2) + (size / 2))] == ' '));
            }
        }
        //printf("%d", failed_direction_change);
        print_maze(field, size);
    }
}

int move(char *field, int size, int pos, int direction) {
    if (direction == 0 && field[pos + 2] == '#' && (floor(pos / size) == floor((pos + 2) / size))) {
        return pos+1;
    } else if (direction == 1 && size * size > (pos + size * 2) && field[pos + 2*size] == '#') {
        return pos + size;
    } else if (direction == 2 && field[pos - 2] == '#' && (floor(pos / size) == floor((pos - 2) / size))) {
        return pos - 1;
    } else if (direction == 3 && 0 < (pos - size * 2) && field[pos - 2 * size] == '#') {
        return pos - size;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    printf("%d\n", size);
    check_args(argc);
    char* field = malloc((size * size) * sizeof(char));

    gen_field(field, size);
    robot_mouse(field, size);
    print_maze(field, size);

    return 0;
}
