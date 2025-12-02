#include <stdio.h>
#include <limits.h>

// Function Delaration
void print_binary(const void *ptr, size_t size);

int main() {

    char alphaChar = 'a';       // Default is Signed char
    printf("alphaChar: %c\n", alphaChar);
    print_binary(&alphaChar, sizeof(alphaChar));

    char numChar = 50;          // If you are storing numbers you must speficy numbers in range only to avoid disaster
    printf("numChar: %d\n", numChar);
    print_binary(&numChar, sizeof(numChar));

    int i = 5;                  // Default is Signed int
    printf("i: %d\n", i);
    print_binary(&i, sizeof(i));

    float f = 15.5;             // Cannot apply `signed`, `unsigned`, `short`, or `long`
    printf("f: %f\n", f);
    print_binary(&f, sizeof(f));

    double d = 66.6;            // Default is not long double
    printf("d: %lf\n", d);
    print_binary(&d, sizeof(d));

    // --- Ranges ---    
    // --- char ---
    signed char sc_min = SCHAR_MIN;
    signed char sc_max = SCHAR_MAX;
    unsigned char uc_max = UCHAR_MAX;

    printf("signed char min: %d\n", sc_min);
    print_binary(&sc_min, sizeof(sc_min));
    printf("signed char max: %d\n", sc_max);
    print_binary(&sc_max, sizeof(sc_max));
    printf("unsigned char max: %u\n", uc_max);
    print_binary(&uc_max, sizeof(uc_max));

    // --- short ---
    short sh_min = SHRT_MIN;        // Default is considered as int
    short sh_max = SHRT_MAX;
    unsigned short ush_max = USHRT_MAX;

    printf("short int min: %d\n", sh_min);
    print_binary(&sh_min, sizeof(sh_min));
    printf("short int max: %d\n", sh_max);
    print_binary(&sh_max, sizeof(sh_max));
    printf("unsigned short int max: %u\n", ush_max);
    print_binary(&ush_max, sizeof(ush_max));

    // --- int ---
    int i_min = INT_MIN;
    int i_max = INT_MAX;
    unsigned int ui_max = UINT_MAX;

    printf("int min: %d\n", i_min);
    print_binary(&i_min, sizeof(i_min));
    printf("int max: %d\n", i_max);
    print_binary(&i_max, sizeof(i_max));
    printf("unsigned int max: %u\n", ui_max);
    print_binary(&ui_max, sizeof(ui_max));

    // --- long ---
    long l_min = LONG_MIN;          // Default is considered as int, long = long int
    long l_max = LONG_MAX;
    unsigned long ul_max = ULONG_MAX;

    printf("long int min: %ld\n", l_min);
    print_binary(&l_min, sizeof(l_min));
    printf("long int max: %ld\n", l_max);
    print_binary(&l_max, sizeof(l_max));
    printf("unsigned long int max: %lu\n", ul_max);
    print_binary(&ul_max, sizeof(ul_max));

    // --- long long ---
    long long ll_min = LLONG_MIN;   // Default is considered as int, long long = long long int
    long long ll_max = LLONG_MAX;
    unsigned long long ull_max = ULLONG_MAX;

    printf("long long int min: %lld\n", ll_min);
    print_binary(&ll_min, sizeof(ll_min));
    printf("long long int max: %lld\n", ll_max);
    print_binary(&ll_max, sizeof(ll_max));
    printf("unsigned long long int max: %llu\n", ull_max);
    print_binary(&ull_max, sizeof(ull_max));

    // Negative number representation by binary flip
    int negativeInt = -50;
    int negativeIntP1 = -51;
    int positiveInt = 50;
    printf("Negative number representation by binary flip:\n");
    printf("Positive number binary:\n");
    print_binary(&positiveInt, sizeof(positiveInt));
    printf("Negative number binary + 1:\n");
    print_binary(&negativeIntP1, sizeof(negativeIntP1));

    printf("Negative number binary:\n");
    print_binary(&negativeInt, sizeof(negativeInt));

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
