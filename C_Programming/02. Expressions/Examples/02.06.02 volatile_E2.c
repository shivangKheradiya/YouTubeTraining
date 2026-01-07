#include <stdio.h>
#include <windows.h>

int main() {
    SYSTEMTIME st;

    while (1) {
        GetLocalTime(&st);

        printf("Date: %02d-%02d-%04d  Time: %02d:%02d:%02d\n",
               st.wDay, st.wMonth, st.wYear,
               st.wHour, st.wMinute, st.wSecond);

        Sleep(1000);  // 1 second
    }

    return 0;
}