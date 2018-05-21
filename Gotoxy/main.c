#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

main(){
  int coluna = 5;
  int linha  = 3;
  char teste[10];

  system("cls");

  gotoxy(coluna, linha);
  printf("Teste");
  gotoxy(coluna, linha+2);
  printf("GotoXY");

  gotoxy(coluna, linha + 3);
  scanf("%s", teste);
  gotoxy(coluna, linha+4);
  printf("%s", teste);
}
