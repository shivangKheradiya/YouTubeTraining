#include <stdio.h>

int series1(void);
int series2(void);

// Declaration for function in file 2
void series_start(int seed);
int series(void);

int main(void) {
    printf("series1 run 1: %d\n", series1() );
    printf("series1 run 2: %d\n", series1() );

    printf("series2 run 1: %d\n", series2() );
    printf("series2 run 2: %d\n", series2() );

    series_start(50);
    printf("series from file 2 run 1: %d\n", series() );
    printf("series from file 2 run 2: %d\n", series() );
    return 0;
}

int series1(void) {
    static int series_num; // initialized once at program start with zero value
    series_num = series_num + 23;
    return series_num;
}

int series2(void) {
    static int series_num = 100; // initialized once at program start
    series_num = series_num + 23;
    return series_num;
}