#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

char dirAtual[255];
int local;

int main() {
    int op;
    char comando[265];


    sprintf(dirAtual, "W!");
    sprintf(comando, "cd %s", dirAtual);
    local = 0;
    if(system(comando)) {
        formatar(0);
    }

    do {
        printf("\t\tMENU\n\t[1] Formatar disco.\n\t[2] Criar pasta.\n\t[3] Criar arquivo.\n\t[4] Alterar diretorio.\n\t[5] Listar arvore de arquivos.\n\t[9] Clear.\n\t[0] Sair.\nEscolha uma opcao\n");
        printf("%s> ", dirAtual);
        scanf("%d%*c", &op);

        switch(op) {
        case 0:
            break;
        case 1:
            formatar(1);
            break;
        case 2:
            criarPasta();
            break;

        case 4:
            alterarDiretorio();
            break;
        case 5:
            listarArvore();
            break;

        case 9:
            system("cls");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }

        sprintf(comando, "cd %s", dirAtual);
        system(comando);
        if(op != 9)
            printf("\n\n");
    } while(op != 0);
}

void addArvore(char nome[255], int aux) {
    FILE *arvore, *arvoreAux;
    int i, j;
    char linha[255], nomePai[255];

    if(aux == 0) {
        arvore = fopen("arvore.txt", "w");
        fprintf(arvore, "%s\n", nome);
        fclose(arvore);
    }
    else {
        arvore = fopen("arvore.txt", "r");

        arvoreAux = fopen("arvoreAux.txt", "w");

        for(i = strlen(dirAtual) - aux - 1; i > 0; i--) {
            if(dirAtual[i] == '\\') {
                strcpy(nomePai, &dirAtual[i + 1]);
                for(i = 0; i < strlen(nomePai); i++)
                    if(nomePai[i] == '\\')
                        nomePai[i] = '\0';
                break;
            }
        }
        if(i == 0)
            strcpy(nomePai, "W!");
        j = 0;
    int u = 0;

        while(!feof(arvore)) {
            fgets(linha, 255, arvore);
            if(linha[strlen(linha) - 1] == '\n')
                linha[strlen(linha) - 1] = '\0';

            fprintf(arvoreAux, "%s\n", linha);
            printf("-%d-%s-", u, linha);
            u++;
            for(i = 0; j == 0, i < strlen(linha); i++) {
                //printf(" i = %d len = %d linha = %s\n", i, strlen(linha), linha);
                if(local == 1) {
                    if(strcmp(&linha[i], nomePai) == 0) {
                        for(i = 0; i < local - 1; i++)
                            fprintf(arvoreAux, "|   ");
                        fprintf(arvoreAux, "|-- %s\n", nome);
                    }
                    j = 1;
                    break;
                }

                else if(linha[i] == ' ' && linha[i + 1] != ' ' && linha[i + 1] != '|') {
                    if(strcmp(&linha[i] + 1, nomePai) == 0) {
                        for(i = 0; i < local - 1; i++)
                            fprintf(arvoreAux, "|   ");
                        fprintf(arvoreAux, "|-- %s\n", nome);
                    }
                    j = 1;
                    break;
                }
            }
            //printf("pos = %d eof = %d\n\n", ftell(arvore), eof(arvore));
        }

        fclose(arvore);
        fclose(arvoreAux);

        remove("arvore.txt");
        rename("arvoreAux.txt", "arvore.txt");
    }
}

void formatar(int aux) {
    char nome[10], comando[30];

    strcpy(nome, "W!");
    sprintf(dirAtual, "%s", nome);

    if(aux == 1) {
        sprintf(comando, "rd %s /s /q", dirAtual);
        system(comando);
    }

    sprintf(comando, "mkdir %s", dirAtual);
    printf("Formatando disco principal. . .\n");

    if(system(comando) == -1) {
        printf("Erro na formatacao!\n");
        exit(1);
    }

    local = 0;

    addArvore(nome, 0);

    printf("Disco formatado com sucesso!\n");
}

void criarPasta() {
    char nome[20], comando[30];

    printf("Nome da pasta: ");
    fgets(nome, 20, stdin);
    nome[strlen(nome) - 1] = '\0';

    sprintf(dirAtual, "%s\\%s", dirAtual, nome);
    sprintf(comando, "mkdir %s", dirAtual);

    if(system(comando) == -1) {
        printf("Erro na criacao da pasta!\n");
        exit(1);
    }
    local++;
    addArvore(nome, strlen(nome) + 1);

}

int listar(char *nome, int op) {
    DIR *dir;
    struct dirent *lsdir;
    int cont = 0;

    dir = opendir(dirAtual);

    printf("[0] Voltar\n");

    while ((lsdir = readdir(dir)) != NULL )
    {
        if(strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0) {
            cont++;
            if(op == 0)
                printf ("[%d] %s\n", cont, lsdir->d_name);
            else if(cont == op)
                strcpy(nome, lsdir->d_name);
        }
    }
    closedir(dir);
    return cont;
}

void listarArvore() {
    FILE *arvore;
    char letra;

    arvore = fopen("arvore.txt", "r");

    while((letra = fgetc(arvore)) != EOF)
        printf("%c", letra);

    fclose(arvore);
}

void alterarDiretorio() {
    int op, max, i;
    char nome[50];

    max = listar(NULL, 0);
    do {
        scanf("%d%*c", &op);
    } while(op > max || op < 0);

    if(op == 0) {
        local--;
        for(i = strlen(dirAtual); i > 0; i--)  {
            printf("%c", dirAtual[i]);
            if(dirAtual[i] == '\\') {
                dirAtual[i] = '\0';
                break;
            }
        }
    }

    if(op != 0) {
        local++;
        listar(nome, op);
        sprintf(dirAtual, "%s\\%s", dirAtual, nome);
    }
}



