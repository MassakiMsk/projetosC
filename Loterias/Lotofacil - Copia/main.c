#include <stdio.h>
#include <stdlib.h>

#define largura 18 //quantidade de numeros no jogo
#define comprimento 15 //quantidade de numeros no resultado

int main()
{
    FILE *arqJogos = NULL;
    int i, j, k, qnt, num, cont;
    int resultado[comprimento];

    arqJogos = fopen("jogos.txt", "r");
    if(arqJogos == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        getchar();
        return 1;
    }

    fscanf(arqJogos, "%d", &qnt);
    int jogos[qnt][largura], total[qnt];

    for(i = 0; i < qnt; i++) {
        fscanf(arqJogos, "%d-", &num);
        for(j = 0; j < largura; j++) {
            fscanf(arqJogos, "%d ", &jogos[num][j]);
        }
    }

    fclose(arqJogos);

    do {
    system("cls");
    printf("Resultado: ");
    for(i = 0; i < comprimento; i++)
        scanf("%d", &resultado[i]);
    printf("\n");
    getchar();

 /*   for(i = 0; i < 20; i++)
        printf("%.2d ", resultado[i]);
    printf("\n");

*/

    for(i = 0; i < qnt; i++) {
        cont = 0;
        for(j = 0; j < largura ; j++) {
            for(k = 0; k < comprimento; k++) {
                if(jogos[i][j] == resultado[k]) {
                    cont++;
                    break;
                }
            }
        }
        total[i] = cont;
    }

/*    for(i = 0; i < qnt; i++) {
            printf("\n%d - ", i);
        for(j = 0; j < largura; j++) {
            printf("%.2d ", jogos[i][j]);
        }
    }
    printf("\n\n\n");
*/
    for(i = 0; i < qnt; i++) {
        if(total[i] > 10 && total[i] != 15)
            printf("Jogo %d --- Acertos %d\n", i, total[i]);
        else if(total[i] == 15) {
            printf("*****************Jogo %d --- Acertos %d\n", i, total[i]);
        }

    }

    printf("\n\nAperte 0 (Zero) para sair ou outro tecla para continuar. . .");
    }while(getch() != '0');
}
