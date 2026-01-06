#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

volatile int flag = 0;   // Without Voletile -O2 or -O3 Will fail
/*
gcc -O0 main.c -o app   # no optimization
gcc -O2 main.c -o app   # high optimization
gcc -O3 main.c -o app   # maximum optimization
*/

void* worker(void* arg) {
    sleep(2);
    flag = 1;           // updated by another thread
    printf("Flag set to 1 in worker\n");
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, worker, NULL);

    printf("Waiting for flag...\n");

    // Without voletile, -O2 or -O3 may become infine loop.
    while (flag == 0) {
        // Compiler may optimize this into: while(1) {}
        // Because it thinks 'flag' never changes in this thread
    }

    printf("Flag updated!\n");
    return 0;
}