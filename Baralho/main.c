#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

typedef struct carta {
    char valor;
    char naipe;
} carta;

typedef struct baralho {
    struct carta *cartas;
    int quantidade;
} baralho;

typedef struct mao {
    carta *cartas;
    int quantidade;
} mao;
void aloca_cartas(carta **cartas, int quan) {
    *cartas = (carta*)realloc(NULL, quan*sizeof(carta));
    if(*cartas == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
}

void aloca_mao(mao **maos, int quan) {
    *maos = (mao*)realloc(NULL, quan*sizeof(mao));
    if(*maos == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
}

void textcolor (int cor) {
    int iColor = cor;

    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void gera_baralho(baralho *monte) {
    char valor[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
    char naipe[] = {'P', 'C', 'E', 'O'};
    int i, j, k;

    srand(time(NULL));

    aloca_cartas(&(monte->cartas), 54);
    monte->quantidade = 0;

    for(i=0;i<54;i++){
        (monte->cartas + i)->valor = ' ';
        (monte->cartas + i)->naipe = ' ';
    }

    while(monte->quantidade < 52) {
        i = rand()%13;
        j = rand()%4;
        for(k = 0; k < monte->quantidade; k++) {
            if((monte->cartas + k)->valor == valor[i] && (monte->cartas + k)->naipe == naipe[j])
                break;
        }
        if(k == monte->quantidade) {
            (monte->cartas + monte->quantidade)->valor = valor[i];
            (monte->cartas + monte->quantidade)->naipe = naipe[j];
            monte->quantidade++;
        }
    }

    while((i = rand()%54)==53);
    (monte->cartas + 52)->valor = (monte->cartas + i)->valor;
    (monte->cartas + 52)->naipe = (monte->cartas + i)->naipe;
    (monte->cartas + i)->valor = 'X';
    (monte->cartas + i)->naipe = '1';
    monte->quantidade++;

    while((j = rand()%54) == i);
    (monte->cartas + 53)->valor = (monte->cartas + j)->valor;
    (monte->cartas + 53)->naipe = (monte->cartas + j)->naipe;
    (monte->cartas + j)->valor = 'X';
    (monte->cartas + j)->naipe = '2';
    monte->quantidade++;

}

void mostrar(baralho monte) {
    int i;
    for(i=0;i<monte.quantidade;i++) {
        if((monte.cartas + i)->naipe == 'C' || (monte.cartas + i)->naipe == 'O' || (monte.cartas + i)->naipe == '1')
            textcolor(12);
        else if((monte.cartas + i)->naipe == 'P' || (monte.cartas + i)->naipe == 'E' || (monte.cartas + i)->naipe == '2')
            textcolor(10);

        if((monte.cartas + i)->valor == 'X') {
            printf("%d -> %s - %c\n", i+1, "Coringa", (monte.cartas+i)->naipe);
        }
        else if((monte.cartas + i)->valor == '0') {
            printf("%d -> %c%c - %c\n", i+1, '1', '0', (monte.cartas+i)->naipe);
        }

        else
            printf("%d -> %c - %c\n", i+1, (monte.cartas+i)->valor, (monte.cartas+i)->naipe);
    }
    textcolor(7);
}

void distribuir(baralho *monte, mao *maos, int quan) {
    int i, j;

    for(i=0; i<2; i++) {
        aloca_cartas(&((maos + i)->cartas), quan);
        for(j=0; j<quan; j++) {
            ((maos + i)->cartas + j)->valor = (monte->cartas + monte->quantidade - 1)->valor;
            ((maos + i)->cartas + j)->naipe = (monte->cartas + monte->quantidade - 1)->naipe;
            monte->quantidade--;
        }
        (maos + i)->quantidade = quan;
    }


}

void mostrar_mao(mao maos) {
    int i;
    for(i=0; i<maos.quantidade; i++)
        printf("\t%c - %c\n", (maos.cartas + i)->valor, (maos.cartas + i)->naipe);
}

int main() {
    baralho monte;
    mao *maos;
    int i;

    aloca_mao(&maos, 2);
    gera_baralho(&monte);
    mostrar(monte);

    distribuir(&monte, maos, 5);
    for(i=0;i<2;i++) {
        printf("Mao %d:\n", i+1);
        mostrar_mao(*(maos+i));
        printf("\n");
    }

}

