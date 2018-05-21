#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define altura 12
#define largura 8

void zera(int mapa[altura][largura][2]);
void randon(int peca[2][4]);
void instancia(int mapa[altura][largura][2]);
void desce(int mapa[altura][largura][2]);
void imprime(int mapa[altura][largura][2]);

int main()
{
    srand(time(NULL));
    int mapa[altura][largura][2];

    zera(mapa);
    int i;
    for(i = 0; i < 10; i++)
    {
        instancia(mapa);
        desce(mapa);
        desce(mapa);
        desce(mapa);
        desce(mapa);
    }

    system("pause");
    return 0;
}

void zera(int mapa[altura][largura][2])
{
    int i, j;

    for(i = 0; i < altura; i++)
        for(j = 0; j < largura; j++)
        {
            mapa[i][j][0] = 0;
            mapa[i][j][1] = 0;
        }
}

void randon(int peca[2][4])
{
    int i, j, aux;
    int pecas[7][2][4] = {{{0, 0, 0, 0}, {1, 1, 1, 1}},
                        {{1, 0, 0, 0}, {1, 1, 1, 0}},
                        {{0, 0, 0, 1}, {0, 1, 1, 1}},
                        {{0, 1, 1, 0}, {0, 1, 1, 0}},
                        {{0, 0, 1, 1}, {0, 1, 1, 0}},
                        {{1, 1, 0, 0}, {0, 1, 1, 0}},
                        {{0, 0, 1, 0}, {0, 1, 1, 1}}};

    aux = rand() % 7;

    for(i = 0; i < 2; i++)
        for(j = 0; j < 4; j++)
            peca[i][j] = pecas[aux][i][j];
}

void instancia(int mapa[altura][largura][2])
{
    int peca[2][4];
    int x, j, aux;

    x = (largura / 2) - 2;
    randon(peca);

    for(aux = 1; aux >= 0; aux--)
    {
        for(j = 0; j < 4; j++)
        {
            mapa[0][x + j][0] = peca[aux][j];
            mapa[0][x + j][1] = 1;
        }
        desce(mapa);
    }
}

void desce(int mapa[altura][largura][2])
{
    int i, j, flag;

    Sleep(500);
    imprime(mapa);
    flag = altura;

    for(i = altura - 1; i > 0; i--)
    {
        for(j = 0; j < largura; j++)
        {
            if(mapa[i - 1][j][1] == 1 && mapa[i][j][0] == 1 && mapa[i][j][1] == 0)
            {
                flag = i;
                printf("%d %d\n", i, j);
                printf("%d %d\n", mapa[i][j][0], mapa[i][j][1]);printf("%d %d\n", mapa[i-1][j][0], mapa[i-1][j][1]);
                //system("pause");
                break;
            }
        }
    }
    for( i = flag - 1; i > 0; i--)
        for(j = 0; j < largura; j++)
        {
            if(mapa[i - 1][j][1] == 1 && mapa[i][j][0] == 0)
            {
                mapa[i][j][0] = mapa[i - 1][j][0];
                mapa[i][j][0] = mapa[i - 1][j][1];
                mapa[i - 1][j][0] = 0;
                mapa[i - 1][j][1] = 0;
            }
        }
}

void imprime(int mapa[altura][largura][2])
{
    int i, aux, j;
    system("cls");

    printf("%c", 218);
    for(j = 0; j < largura; j++)
        printf("%c%c%c", 196, 196, 196);
    printf("%c", 191);
    printf("\n");

    for(i = 0; i < altura; i++)
    {
        for(aux = 0; aux < 2; aux++)
        {
            printf("%c", 179);
            for(j = 0; j < largura; j++)
            {
                if(mapa[i][j][0] == 1 && aux == 0)
                    printf("%c%c%c", 201, 205, 187);
                else if(mapa[i][j][0] == 1 && aux == 1)
                    printf("%c%c%c", 200, 205, 188);
                else
                    printf("   ");
            }
            printf("%c\n", 179);
        }
    }

    printf("%c", 192);
    for(j = 0; j < largura; j++)
        printf("%c%c%c", 196, 196, 196);
    printf("%c", 217);
    printf("\n");
}
