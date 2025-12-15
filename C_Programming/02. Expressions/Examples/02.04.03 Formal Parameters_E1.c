#include <stdio.h>

int is_in(char *s, char c);

int main() {
    char *fName = "Shivang";
    char chr = 'a';
    printf("%s : %d\n", fName , is_in(fName, chr));

    char *lName = "Kheradiya";
    printf("%s : %d", lName , is_in(lName, chr));
    return 0;
}

/* Return 1 if c is part of string s; 0 otherwise */
int is_in(char *s, char c) {
    // *s and c are the new instance seperate from *name and chr
    // Topics Will be covered in Upcoming vides e.g. Pointers , Call by value & Call by reference
    while(*s)
        if(*s == c) {
            s = "ABCD";     // Redefination of Formal Parameters are possible
            return 1;
        }
        else s++;
    return 0;
}