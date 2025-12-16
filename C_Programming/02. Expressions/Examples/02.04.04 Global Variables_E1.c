#include <stdio.h>

// #include "abcd.h"        Global Variable is possible to define in different file too

int count;                  /* count is global */

void func1(void);
void func2(void);

int main(void) {
    count = 100;            /* count is global */
    func1();
    return 0;
}

void func1(void) {
    int temp;
    temp = count;           // accessing global variable
    func2();
    printf("count global variable is %d\n", count); // prints 100
}

void func2(void) {
    int count;              // local variable hides global count because of higher precedence
    // extern int count;    // Considers Global Variable
    for(count = 1; count < 10; count++)
        printf("count local variable is %d\n", count);
}