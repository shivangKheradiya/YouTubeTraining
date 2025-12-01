#include <stdio.h>

void printLong();

int main() {
    char chr = 'C';
    printf("Value: %c\n", chr);
    printf("Memory size: %zu bytes\n", sizeof(chr));

    int number = 50;
    printf("Value: %d\n", number);
    printf("Memory size: %zu bytes\n", sizeof(number));

    float floatNumber = 50;
    printf("Value: %f\n", floatNumber);
    printf("Memory size: %zu bytes\n", sizeof(floatNumber));

    double doubleNumber = 50;
    printf("Value: %lf\n", doubleNumber);
    printf("Memory size: %zu bytes\n", sizeof(doubleNumber));

    // Demonstrates the Void Return Type
    printLong();

    return 0;
}

void printLong(){
    long lgInt = 5;
    printf("Value: %ld\n", lgInt);
    printf("Memory size: %zu bytes\n", sizeof(lgInt));
}