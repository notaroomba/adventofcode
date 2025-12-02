#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char line_buffer[4];
    int code = 0;
    int angle = 50;
    FILE *fptr = fopen("1.txt", "r");
    while (fgets(line_buffer, sizeof(line_buffer), fptr) != NULL) {
        int m = line_buffer[0] == 'L' ? -1 : 1;
        code = atoi(&line_buffer[1]);
        angle += m * code;
        if (angle < 0) {
            angle = 90 + angle;
        } else if (angle > 99) {
            angle = angle - 99;
        } else {
            angle = 0;
            code++;
        }
    }
    printf("The code is: %d\n", angle);
    fclose(fptr);
    return 0;
}