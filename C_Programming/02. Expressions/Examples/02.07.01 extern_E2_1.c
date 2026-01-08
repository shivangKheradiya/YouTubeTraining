#include <stdio.h>

// global definition of x, y and ch
int x = 10, y = 20;
char ch = 'X';

void func1(void);   // Function Declaration
void func22(void);  // Function Declaration
void func23(void);  // Function Declaration 
void func12(void);  // Function Declaration 

int main(void) {
    /* ... */
    func22();       // Defination is in 02.07.01 extern_E2_2.c and demonstrate global variable change using extern
    func23();       // Defination is in 02.07.01 extern_E2_2.c and demonstrate global variable change using extern
    
    func12();

    func1();

    extern int z;   // Defination is in 02.07.01 extern_E2_2.c
    printf("x global: %d\n", x);
    printf("z global: %d\n", z);
    return 0;
}

void func1(void) {
    x = 123;        // Direct Global variable can be used as it's defined in same file after variable definition
}

void func12(void) {
    int x = 20;              // local x shadows global x
    {
        int x = 5;           // inner block x shadows outer x as well as global variables
        // extern int x;     // extern give global x value in other words The compiler resolves undeclared variables by checking enclosing blocks, then global scope.
        
        // same variable name can't be use 2 times
        // int x = 5; 
        // extern int x;

        printf("x from inner block :%d\n", x);   // prints inner block or extern variable
    }
}
