#include <stdio.h>
#include <limits.h>

// Function Delaration
void print_binary(const void *ptr, size_t size);

int main() {

    short int i = 32767;
    short int iMinus = -1;
    unsigned short int ui = 65535;

    printf("short int i: %d\n", i);
    print_binary(&i, sizeof(i));

    printf("short int iMinus: %d\n", iMinus);
    print_binary(&iMinus, sizeof(iMinus));

    printf("unsigned short int ui: %u\n", ui);
    print_binary(&ui, sizeof(ui));

    return 0;
}

// Generic binary printer
void print_binary(const void *ptr, size_t size) {
    const unsigned char *bytes = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        unsigned char byte = bytes[size - 1 - i]; // MSB first
        for (int bit = 7; bit >= 0; bit--) {
            putchar((byte & (1u << bit)) ? '1' : '0');
        }
    }
    putchar('\n');
}
