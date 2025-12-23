#include <stdio.h>

const int a = 10;

void sp_to_dash(const char *str);
void modifyA();

int main(void) {
    modifyA();
    sp_to_dash("this is a test");
    return 0;
}

/// @brief `const char *str` ensures that the function cannot alter the string passed to it.
/// @param str 
void sp_to_dash(const char *str) {
    while(*str) {
        if(*str == ' '){
            printf("%c", '-');
            // *str = '-'; // ❌ Not allowed, str is const. so, Attempting to modify the string would result in a **compile-time error**.
        }
        else printf("%c", *str);
        str++;
    }
}

void modifyA(){
    // a = 5;               // ❌ Not allowed, a is const. so, Attempting to modify the string would result in a **compile-time error**.
}