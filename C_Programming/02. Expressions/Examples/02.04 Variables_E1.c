#include <stdio.h>

int main() {
    int z;                  // Variable Declaration

    // Importance for delaration with prelimirary(sentinel) value
    printf("Value z: %d", z);

    int x = 0, y = z = 0;   // Variable Declaration with Initialization/ Assignment
    printf("Value z: %d", z);// Variable Initialization/ Assignment

    return 0;
}