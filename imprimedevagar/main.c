#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main()
{
    char frase2[] = "Esse eh um teste legal";
    int i, delay = 20;
    char c;

    for(i = 0; frase2[i] != '\0'; i++) {
        putchar(frase2[i]);
        Sleep(delay);
        if(kbhit()) {
            c = getch();
            delay = 0;
        }
    }
}
