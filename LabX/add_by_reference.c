#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of three integers
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <num1> <num2> <num3>\n", argv[0]);
        return 1;
    }
    // Convert the strings passed to program to integers
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);

    int sum = add(&x, &y, &z);
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);
    return 0;
}
