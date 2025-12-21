#include <stdio.h>

/* -------------------------------
   1. FILE SCOPE
   -------------------------------
   Variables declared outside all functions
   are visible from this point to the end
   of the file.
---------------------------------*/
int file_scope_var = 10;

/* --------------------------------
   2. FUNCTION PROTOTYPE SCOPE
   --------------------------------
   The names inside a function prototype
   exist ONLY inside the prototype.
   They do NOT affect anything else.
-----------------------------------*/
void demo(int prototype_var);   // prototype_var exists ONLY here

/* Function declaration with different parameter name */
void demo(int x) {              // x is NOT the same as prototype_var
    printf("Inside demo(): x = %d\n", x);
}

int main(void) {

    printf("File-scope variable: %d\n", file_scope_var);

    /* -------------------------------
       3. BLOCK SCOPE
       -------------------------------
       Variables declared inside a block
       (inside { ... }) exist only inside
       that block.
    -----------------------------------*/
    {
        int block_scope_var = 20;
        printf("Inside block: block_scope_var = %d\n", block_scope_var);

        /* This modifies the FILE-SCOPE variable */
        file_scope_var = 99;
    }

    /* block_scope_var is NOT visible here */
    // printf("%d", block_scope_var);  // ERROR if uncommented

    printf("File-scope variable after block: %d\n", file_scope_var);

    /* -------------------------------
       4. FUNCTION SCOPE
       -------------------------------
       Labels used with goto have
       function scope.
    -----------------------------------*/
    goto jump_here;

    printf("This line is skipped.\n");

jump_here:   // label has function scope
    printf("Jumped using a label with function scope.\n");

    /* Call function to show prototype scope vs parameter scope */
    int argValue = 123;
    demo(argValue);

    return 0;
}