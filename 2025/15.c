#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char line_buffer[100];
    int code = 0;
    int angle = 50;
    FILE *fptr = fopen("1.txt", "r");
    while (fgets(line_buffer, sizeof(line_buffer), fptr) != NULL) {
        int m = line_buffer[0] == 'L' ? -1 : 1;
        int value = atoi(&line_buffer[1]);
        angle += m * value;
        angle = ((angle % 100) + 100) % 100;
        if (angle < 0) {
            angle = 100 + angle;
        } else if (angle > 99) {
            angle = angle - 100;
        }
        if (angle == 0) {
            code++;
            code += ((value) / 100) - (value %100) / 100;
        }
    }
        printf("The code is: %i\n", code);
    fclose(fptr);
    return 0;
}