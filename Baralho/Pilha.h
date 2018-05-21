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

void gera_baralho() {

}
