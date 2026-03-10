static int series_num;

int series(void) {
    series_num = series_num + 23;
    return series_num;
}

/* initialize series_num */
void series_start(int seed) {
    series_num = seed;
}