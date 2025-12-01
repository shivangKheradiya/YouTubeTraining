#include <stdio.h>
#include <stdlib.h>

int globalVar = 123; // Stored in data segment

void checkMemory() {
    // Local variable → allocated on the stack
    int stackVar = 42;

    // Dynamically allocated variable → allocated on the heap
    int *heapVar = (int *)malloc(sizeof(int));
    *heapVar = 99;

    printf("Address of stackVar: %p (stack)\n", (void*)&stackVar);
    printf("Address of heapVar:  %p (heap)\n", (void*)heapVar);

    // Free heap memory after use
    free(heapVar);
}

int main() {
    checkMemory();
    int stackVar = 42;
    int *heapVar = malloc(sizeof(int));
    *heapVar = 99;

    printf("Address of globalVar: %p (data segment)\n", (void*)&globalVar);
    printf("Address of stackVar:  %p (stack)\n", (void*)&stackVar);
    printf("Address of heapVar:   %p (heap)\n", (void*)heapVar);

    free(heapVar);
    return 0;
}