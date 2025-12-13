#include <stdio.h>

void func1(void);
void func2(void);
void InnerBlock(void);
void GetString(void);
void DemoAuto(void);
void CounterFunction(void);

int main() {

    // "//" Comments may not supported in C89 so try and see the output with different compilers

    DemoAuto();

    func1();
    func2();
    /* Here, `x` in `func1` and `x` in `func2` are completely independent. Each exists only within its own function. */

    InnerBlock();
    /* The inner `x` hides the outer `x` inside the `if` block. Once the block ends, the outer `x` becomes visible again. */

    GetString();

    // Static Variable is increasing the counter whenever function is called but local variable is reinitializing
    CounterFunction();
    CounterFunction();
    return 0;
}

void func1(void) {
    int x;
    x = 10;
}

void func2(void) {
    int x;
    x = -199;
}

void InnerBlock(void) {
    int x;
    x = 10;

    if(x == 10) {
        int x;                                  /* hides the outer x */
        x = 99;
        printf("Inner x: %d\n", x);
    }
    printf("Outer x: %d\n", x);
}

void GetString(void) {
    int t;
    printf("Enter a Number: ");
    scanf("%d", &t);

    if(t == 1) {
        char s[80];                             /* created only upon entry */
        printf("Enter name: ");
        scanf("%79s",s);
        printf("Enterd name: %s\n", s);
        /* s is valid only inside this block */ 
    }

    printf("s is not accessible here");
    /* s is not accessible here */ 
    /* printf("Enterd name: %s", s); */ 
}

void DemoAuto(void) {
    auto int x = 10;   // explicitly declared as auto
    int y = 20;        // implicitly auto (default for local variables)

    printf("x = %d, y = %d\n", x, y);
}

void CounterFunction(void) {
    static int StaticCount = 0;   // static variable, initialized only once
    int LocalCount = 10;
    StaticCount++;                // retains its value across calls
    LocalCount++;
    printf("Static Count = %d\n", StaticCount);
    printf("Local Count = %d\n", LocalCount);
}

