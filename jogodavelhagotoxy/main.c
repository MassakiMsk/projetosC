#include <stdio.h>
#include<stdlib.h>
#include <windows.h>

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void imprime() {
    int i;

    gotoxy(0, 0);

    for(i = 0; i < 7; i++)
        printf("           |           |\n");
    printf("- - - - - - - - - - - - - - - - - -\n");
    for(i = 0; i < 7; i++)
        printf("           |           |\n");
    printf("- - - - - - - - - - - - - - - - - -\n");
    for(i = 0; i < 6; i++)
        printf("           |           |\n");
    printf("           |           |");

    gotoxy(38, 10);
    printf("Insira a coordenada Vertical");
    gotoxy(43, 11);
    printf("e pressione Enter");
    gotoxy(45, 12);
    printf("***** *****");
    gotoxy(45, 13);
    printf("*   * *   *");
    gotoxy(45, 14);
    printf("***** *****");
}

void reseta(int jogo[3][3]) {
    int i, j;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            jogo[i][j] = 0;

    imprime();
    gotoxy(47, 13);
}

int jogada(int jogo[3][3], int x, int y, int op) {

    gotoxy(47, 13);
    printf(" ");
    gotoxy(53, 13);
    printf(" ");

    if(jogo[x][y] != 0) {
        return 0;
    }

    if(op == 1) {
        gotoxy(2 + x * 12, 2 + y * 8);
        printf("x       x");
        gotoxy(2 + x * 12, 3 + y * 8);
        printf("  x   x");
        gotoxy(2 + x * 12, 4 + y * 8);
        printf("    x");
        gotoxy(2 + x * 12, 5 + y * 8);
        printf("  x   x");
        gotoxy(2 + x * 12, 6 + y * 8);
        printf("x       x");
    }

    else if(op == -1) {
        gotoxy(2 + x * 12, 2 + y * 8);
        printf("  o o o");
        gotoxy(2 + x * 12, 3 + y * 8);
        printf("o       o");
        gotoxy(2 + x * 12, 4 + y * 8);
        printf("o       o");
        gotoxy(2 + x * 12, 5 + y * 8);
        printf("o       o");
        gotoxy(2 + x * 12, 6 + y * 8);
        printf("  o o o");
    }

    jogo[x][y] = op;
    return op;
}

int confere(int jogo[3][3]) {
    if((jogo[0][0] + jogo [0][1] + jogo [0][2] == 3)||(jogo[0][0] + jogo [0][1] + jogo [0][2] == -3))
        return jogo[0][0];
    if((jogo[1][0] + jogo [1][1] + jogo [1][2] == 3)||(jogo[1][0] + jogo [1][1] + jogo [1][2] == -3))
        return jogo[1][0];
    if((jogo[2][0] + jogo [2][1] + jogo [2][2] == 3)||(jogo[2][0] + jogo [2][1] + jogo [2][2] == -3))
        return jogo[2][0];
    if((jogo[0][0] + jogo [1][0] + jogo [2][0] == 3)||(jogo[0][0] + jogo [1][0] + jogo [2][2] == -3))
        return jogo[0][0];
    if((jogo[0][1] + jogo [1][1] + jogo [2][1] == 3)||(jogo[0][1] + jogo [1][1] + jogo [2][1] == -3))
        return jogo[0][1];
    if((jogo[0][2] + jogo [1][2] + jogo [2][2] == 3)||(jogo[0][2] + jogo [1][2] + jogo [2][2] == -3))
        return jogo[0][2];
    if((jogo[0][0] + jogo [1][1] + jogo [2][2] == 3)||(jogo[0][0] + jogo [1][1] + jogo [2][2] == -3))
        return jogo[0][0];
    if((jogo[0][2] + jogo [1][1] + jogo [2][0] == 3)||(jogo[0][2] + jogo [1][1] + jogo [2][0] == -3))
        return jogo[0][2];
    return 0;
}

int main() {
    int jogo[3][3];
    int x, y, op, aux;
    reseta(jogo);
    op = 1;

    while(confere(jogo) == 0) {
        do{
            gotoxy(38, 10);
            printf("Insira a coordenada Vertical   ");
            gotoxy(47, 13);
            scanf("%d", &y);

            gotoxy(38, 10);
            printf("Insira a coordenada Horizontal");
            gotoxy(53, 13);
            scanf("%d", &x);

            aux = jogada(jogo, x, y, op);
        } while(aux == 0);
        op *= -1;
    }

    gotoxy(44, 13);
    printf("Alguem ganhou!");
    getchar();
    getchar();
    gotoxy(0, 50);
    return 0;
}


/*

           |           |
           |           |
           |           |
           |           |
           |           |
           |           |
           |           |
- - - - - - - - - - - - - - - - - -
           |           |
           |           |             Insira a coordenada Vertical
           |           |                  e pressione ENTER
           |           |                    ***** *****
           |           |                    *   * *   *
           |           |                    ***** *****
           |           |
- - - - - - - - - - - - - - - - - -
           |           |
           |           |
           |           |
           |           |
           |           |
           |           |
           |           |


x       x
  x   x
    x
  x   x
x       *

  o o o
o       o
o       o
o       o
  o o o



*/
