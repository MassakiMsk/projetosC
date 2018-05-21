#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arqJogos = NULL;
    int i, j, k, l, qnt, num, num1, cont;
    int resultado[20];

    arqJogos = fopen("jogos.txt", "r");
    if(arqJogos == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        getchar();
        return 1;
    }

    fscanf(arqJogos, "%d", &qnt);
    int jogos[qnt][21][50], total[qnt][21];

    for(i = 0; i < qnt * 21; i++) {
        fscanf(arqJogos, "%d-%d-", &num, &num1);
        for(j = 0; j < 50; j++) {
            fscanf(arqJogos, "%d ", &jogos[num][num1][j]);
        }
    }

    fclose(arqJogos);
    do{
    system("cls");
    printf("Resultado: ");
    for(i = 0; i < 20; i++)
        scanf("%d", &resultado[i]);
    printf("\n");
    getchar();

    for(i = 0; i < qnt; i++)
        for(l = 0; l < 21; l++) {
            cont = 0;
            for(j = 0; j < 50 ; j++) {
                for(k = 0; k < 20; k++) {
                    if(jogos[i][l][j] == resultado[k]) {
                        cont++;
                        break;
                    }
                }
            }
            total[i][l] = cont;
        }

 /*   for(i = 0; i < qnt; i++)
        for(l = 0; l < 21; l++){
            printf("\n%d-%d- ", i, l);
        for(j = 0; j < 50; j++) {
            printf("%.2d ", jogos[i][l][j]);
        }
    } */
    printf("\n\n\n");

    for(i = 0; i < qnt; i++)
        for(l = 0; l < 21; l++)
            if(total[i][l] >= 15)
        printf("Jogo %d-%d --- Acertos %d\n", i + 1, l + 1, total[i][l]);

        printf("Digite 0 para finalizar ou outra tecla para conferir novamente. . .");
    }while(getch() != '0');
}
