#include <stdio.h>
#include <cs50.h>

int askForHeight(void);
void buildPyramid(int height);
void printSpaces(int spaces);
void printBlocks(int blocks);

int main(void) {
    int height = askForHeight();
    buildPyramid(height);
}

int askForHeight(void) {
    int h;
    do {
        h = get_int("How tall should the pyramid be?\n");
    } while (h < 1 || h > 8); // Can remove the constraint for numbers greater than 8 just for fun!
    return h;
}

void buildPyramid(int height) {
    int rows = height;
    int spaces = height - 1;
    int blocks = height - spaces;

    for (int h = 0; h < rows; h++) {
        printSpaces(spaces);
        printBlocks(blocks);
        printf("  ");
        printBlocks(blocks);
        printf("\n");
        spaces--;
        blocks++;
    }
}

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void printBlocks(int blocks) {
    for (int j = 0; j < blocks; j++) {
        printf("#");
    }
}