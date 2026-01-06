#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int flagValue = 0;
const volatile int *flag = &flagValue;

void* worker(void* arg) {
    sleep(2);
    flagValue = 1;
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