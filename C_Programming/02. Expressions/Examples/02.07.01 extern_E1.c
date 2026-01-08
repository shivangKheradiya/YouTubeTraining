#include <stdio.h>

int main(void) {
    
    extern int first, last; // declare global vars
    // Here, `extern` tells the compiler that `first` and `last` exist elsewhere, allowing them to be used before their definition.
    
    printf("%d %d", first, last);
    return 0;
}

// global definition of first and last
int first = 10, last = 20;