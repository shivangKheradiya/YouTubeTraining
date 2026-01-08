
// Here, `extern` ensures that `x`, `y`, and `ch` are recognized in File Two without redefining them. The linker resolves all references during compilation.
extern int x, y;
extern char ch;
extern int z = 5;       // Direct declaration-defination will create a global variable z

// Function Defination
void func22(void) {
    x = y / 10;
}

// Function Defination
void func23(void) {
    y = 10;
}