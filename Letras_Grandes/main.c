#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(char ****letras, int linhas, int altura, int largura) {
    int i, j;
    *letras = (char***)realloc(*letras, sizeof(char**)*linhas);
    if(*letras == NULL)
        printf("Erro 1\n");

    for(i=0;i<linhas;i++) {
        *(*letras+i) = (char**)malloc(sizeof(char*)*altura);
        if(*(*letras+i) == NULL)
            printf("Erro 2\n");
    }

    for(i=0;i<linhas;i++) {
        for(j=0;j<altura;j++) {
            *(*(*letras+i)+j) = (char*)malloc(sizeof(char)*largura);
            if(*(*(*letras+i)+j) == NULL)
                printf("Erro 3\n");
        }
    }
}

void mostra_frase(char ***letras, int linhas, int altura, int largura) {
    int i, j;
    for(i=0;i<linhas;i++){
        for(j=0;j<altura;j++) {
            printf("%s\n", *(*(letras+i)+j));
        }
        printf("\n");
    }
}

void atribui(char ***letras, char *palavra, int linhas, int altura, int largura) {
    int i, j;

    for(i=0;i<linhas;i++) {
        for(j=0;j<altura;j++) {
            *(*(*(letras+i)+j))='\0';
        }
    }

    j=0;

    for(i=0;i<strlen(palavra);i++){
        if(strlen(*(*(letras+j))) + tamanho((palavra+i)) > largura)
            j++;
        if(j==linhas)
            break;
        switch(*(palavra+i)){
        case 'a':
            strcat(*(*(letras+j)+0), " AAA   ");
            strcat(*(*(letras+j)+1), "A   A  ");
            strcat(*(*(letras+j)+2), "AAAAA  ");
            strcat(*(*(letras+j)+3), "A   A  ");
            strcat(*(*(letras+j)+4), "A   A  ");
            break;
        case 'b':
            strcat(*(*(letras+j)+0), "BBBB   ");
            strcat(*(*(letras+j)+1), "B   B  ");
            strcat(*(*(letras+j)+2), "BBBB   ");
            strcat(*(*(letras+j)+3), "B   B  ");
            strcat(*(*(letras+j)+4), "BBBB   ");
            break;
        case 'c':
            strcat(*(*(letras+j)+0), "CCCCC  ");
            strcat(*(*(letras+j)+1), "C      ");
            strcat(*(*(letras+j)+2), "C      ");
            strcat(*(*(letras+j)+3), "C      ");
            strcat(*(*(letras+j)+4), "CCCCC  ");
            break;
        case 'd':
            strcat(*(*(letras+j)+0), "DDDD   ");
            strcat(*(*(letras+j)+1), "D   D  ");
            strcat(*(*(letras+j)+2), "D   D  ");
            strcat(*(*(letras+j)+3), "D   D  ");
            strcat(*(*(letras+j)+4), "DDDD   ");
            break;
        case 'e':
            strcat(*(*(letras+j)+0), "EEEEE  ");
            strcat(*(*(letras+j)+1), "E      ");
            strcat(*(*(letras+j)+2), "EEE    ");
            strcat(*(*(letras+j)+3), "E      ");
            strcat(*(*(letras+j)+4), "EEEEE  ");
            break;
        case 'f':
            strcat(*(*(letras+j)+0), "FFFFF  ");
            strcat(*(*(letras+j)+1), "F      ");
            strcat(*(*(letras+j)+2), "FFF    ");
            strcat(*(*(letras+j)+3), "F      ");
            strcat(*(*(letras+j)+4), "E      ");
            break;
        case 'g':
            strcat(*(*(letras+j)+0), " GGGG  ");
            strcat(*(*(letras+j)+1), "G      ");
            strcat(*(*(letras+j)+2), "G GGG  ");
            strcat(*(*(letras+j)+3), "G   G  ");
            strcat(*(*(letras+j)+4), " GGG   ");
            break;
        case 'h':
            strcat(*(*(letras+j)+0), "H   H  ");
            strcat(*(*(letras+j)+1), "H   H  ");
            strcat(*(*(letras+j)+2), "HHHHH  ");
            strcat(*(*(letras+j)+3), "H   H  ");
            strcat(*(*(letras+j)+4), "H   H  ");
            break;
        case 'i':
            strcat(*(*(letras+j)+0), "I  ");
            strcat(*(*(letras+j)+1), "   ");
            strcat(*(*(letras+j)+2), "I  ");
            strcat(*(*(letras+j)+3), "I  ");
            strcat(*(*(letras+j)+4), "I  ");
            break;
        case 'j':
            strcat(*(*(letras+j)+0), "    J  ");
            strcat(*(*(letras+j)+1), "    J  ");
            strcat(*(*(letras+j)+2), "    J  ");
            strcat(*(*(letras+j)+3), "J   J  ");
            strcat(*(*(letras+j)+4), " JJJ   ");
            break;
        case 'k':
            strcat(*(*(letras+j)+0), "K  K  ");
            strcat(*(*(letras+j)+1), "K K   ");
            strcat(*(*(letras+j)+2), "KK    ");
            strcat(*(*(letras+j)+3), "K K   ");
            strcat(*(*(letras+j)+4), "K  K  ");
            break;
        case 'l':
            strcat(*(*(letras+j)+0), "L      ");
            strcat(*(*(letras+j)+1), "L      ");
            strcat(*(*(letras+j)+2), "L      ");
            strcat(*(*(letras+j)+3), "L      ");
            strcat(*(*(letras+j)+4), "LLLLL  ");
            break;
        case 'm':
            strcat(*(*(letras+j)+0), "M     M  ");
            strcat(*(*(letras+j)+1), "MM   MM  ");
            strcat(*(*(letras+j)+2), "M M M M  ");
            strcat(*(*(letras+j)+3), "M  M  M  ");
            strcat(*(*(letras+j)+4), "M     M  ");
            break;
        case 'n':
            strcat(*(*(letras+j)+0), "N   N  ");
            strcat(*(*(letras+j)+1), "NN  N  ");
            strcat(*(*(letras+j)+2), "N N N  ");
            strcat(*(*(letras+j)+3), "N  NN  ");
            strcat(*(*(letras+j)+4), "N   N  ");
            break;
        case 'o':
            strcat(*(*(letras+j)+0), " OOO   ");
            strcat(*(*(letras+j)+1), "O   O  ");
            strcat(*(*(letras+j)+2), "O   O  ");
            strcat(*(*(letras+j)+3), "O   O  ");
            strcat(*(*(letras+j)+4), " OOO   ");
            break;
        case 'p':
            strcat(*(*(letras+j)+0), "PPPP   ");
            strcat(*(*(letras+j)+1), "P   P  ");
            strcat(*(*(letras+j)+2), "PPPP   ");
            strcat(*(*(letras+j)+3), "p      ");
            strcat(*(*(letras+j)+4), "p      ");
            break;
        case 'q':
            strcat(*(*(letras+j)+0), "QQQQQ   ");
            strcat(*(*(letras+j)+1), "Q   Q   ");
            strcat(*(*(letras+j)+2), "Q   Q   ");
            strcat(*(*(letras+j)+3), "Q  QQ   ");
            strcat(*(*(letras+j)+4), "QQQQQQ  ");
            break;
        case 'r':
            strcat(*(*(letras+j)+0), "RRRR   ");
            strcat(*(*(letras+j)+1), "R   R  ");
            strcat(*(*(letras+j)+2), "RRRR   ");
            strcat(*(*(letras+j)+3), "R R    ");
            strcat(*(*(letras+j)+4), "R  R   ");
            break;
        case 's':
            strcat(*(*(letras+j)+0), " SSSS  ");
            strcat(*(*(letras+j)+1), "S      ");
            strcat(*(*(letras+j)+2), " SSS   ");
            strcat(*(*(letras+j)+3), "    S  ");
            strcat(*(*(letras+j)+4), "SSSS   ");
            break;
        case 't':
            strcat(*(*(letras+j)+0), "TTTTTTT  ");
            strcat(*(*(letras+j)+1), "   T     ");
            strcat(*(*(letras+j)+2), "   T     ");
            strcat(*(*(letras+j)+3), "   T     ");
            strcat(*(*(letras+j)+4), "   T     ");
            break;
        case 'u':
            strcat(*(*(letras+j)+0), "U   U  ");
            strcat(*(*(letras+j)+1), "U   U  ");
            strcat(*(*(letras+j)+2), "U   U  ");
            strcat(*(*(letras+j)+3), "U   U  ");
            strcat(*(*(letras+j)+4), " UUU   ");
            break;
        case 'v':
            strcat(*(*(letras+j)+0), "V       V  ");
            strcat(*(*(letras+j)+1), " V     V   ");
            strcat(*(*(letras+j)+2), "  V   V    ");
            strcat(*(*(letras+j)+3), "   V V     ");
            strcat(*(*(letras+j)+4), "    V      ");
            break;
        case 'w':
            strcat(*(*(letras+j)+0), "W     W  ");
            strcat(*(*(letras+j)+1), "W  W  W  ");
            strcat(*(*(letras+j)+2), "W W W W  ");
            strcat(*(*(letras+j)+3), "WW   WW  ");
            strcat(*(*(letras+j)+4), "W     W  ");
            break;
        case 'x':
            strcat(*(*(letras+j)+0), "X   X  ");
            strcat(*(*(letras+j)+1), " X X   ");
            strcat(*(*(letras+j)+2), "  X    ");
            strcat(*(*(letras+j)+3), " X X   ");
            strcat(*(*(letras+j)+4), "X   X  ");
            break;
        case 'y':
            strcat(*(*(letras+j)+0), "Y   Y  ");
            strcat(*(*(letras+j)+1), " Y Y   ");
            strcat(*(*(letras+j)+2), "  Y    ");
            strcat(*(*(letras+j)+3), "  Y    ");
            strcat(*(*(letras+j)+4), "  Y    ");
            break;
        case 'z':
            strcat(*(*(letras+j)+0), "ZZZZZ  ");
            strcat(*(*(letras+j)+1), "   Z   ");
            strcat(*(*(letras+j)+2), "  Z    ");
            strcat(*(*(letras+j)+3), " Z     ");
            strcat(*(*(letras+j)+4), "ZZZZZ  ");
            break;
        case '0':
            strcat(*(*(letras+j)+0), " 0000   ");
            strcat(*(*(letras+j)+1), "0    0  ");
            strcat(*(*(letras+j)+2), "0    0  ");
            strcat(*(*(letras+j)+3), "0    0  ");
            strcat(*(*(letras+j)+4), " 0000   ");
            break;
        case '1':
            strcat(*(*(letras+j)+0), " 11    ");
            strcat(*(*(letras+j)+1), "1 1    ");
            strcat(*(*(letras+j)+2), "  1    ");
            strcat(*(*(letras+j)+3), "  1    ");
            strcat(*(*(letras+j)+4), "11111  ");
            break;
        case '2':
            strcat(*(*(letras+j)+0), " 222   ");
            strcat(*(*(letras+j)+1), "2   2  ");
            strcat(*(*(letras+j)+2), "   2   ");
            strcat(*(*(letras+j)+3), " 2     ");
            strcat(*(*(letras+j)+4), "22222  ");
            break;
        case '3':
            strcat(*(*(letras+j)+0), "3333   ");
            strcat(*(*(letras+j)+1), "    3  ");
            strcat(*(*(letras+j)+2), "  33   ");
            strcat(*(*(letras+j)+3), "    3  ");
            strcat(*(*(letras+j)+4), "3333   ");
            break;
        case '4':
            strcat(*(*(letras+j)+0), "4   4  ");
            strcat(*(*(letras+j)+1), "4   4  ");
            strcat(*(*(letras+j)+2), "44444  ");
            strcat(*(*(letras+j)+3), "    4  ");
            strcat(*(*(letras+j)+4), "    4  ");
            break;
        case '5':
            strcat(*(*(letras+j)+0), "55555  ");
            strcat(*(*(letras+j)+1), "5      ");
            strcat(*(*(letras+j)+2), "55555  ");
            strcat(*(*(letras+j)+3), "    5  ");
            strcat(*(*(letras+j)+4), "55555  ");
            break;
        case '6':
            strcat(*(*(letras+j)+0), " 666   ");
            strcat(*(*(letras+j)+1), "6      ");
            strcat(*(*(letras+j)+2), "6666   ");
            strcat(*(*(letras+j)+3), "6   6  ");
            strcat(*(*(letras+j)+4), " 666   ");
            break;
        case '7':
            strcat(*(*(letras+j)+0), "77777  ");
            strcat(*(*(letras+j)+1), "   7   ");
            strcat(*(*(letras+j)+2), "  7    ");
            strcat(*(*(letras+j)+3), " 7     ");
            strcat(*(*(letras+j)+4), "7      ");
            break;
        case '8':
            strcat(*(*(letras+j)+0), " 888   ");
            strcat(*(*(letras+j)+1), "8   8  ");
            strcat(*(*(letras+j)+2), " 888   ");
            strcat(*(*(letras+j)+3), "8   8  ");
            strcat(*(*(letras+j)+4), " 888   ");
            break;
        case '9':
            strcat(*(*(letras+j)+0), " 999   ");
            strcat(*(*(letras+j)+1), "9   9  ");
            strcat(*(*(letras+j)+2), " 9999  ");
            strcat(*(*(letras+j)+3), "    9  ");
            strcat(*(*(letras+j)+4), " 999   ");
            break;
        case ',':
            strcat(*(*(letras+j)+0), "    ");
            strcat(*(*(letras+j)+1), "    ");
            strcat(*(*(letras+j)+2), " ,  ");
            strcat(*(*(letras+j)+3), " ,  ");
            strcat(*(*(letras+j)+4), ",   ");
            break;
        case '!':
            strcat(*(*(letras+j)+0), "!  ");
            strcat(*(*(letras+j)+1), "!  ");
            strcat(*(*(letras+j)+2), "!  ");
            strcat(*(*(letras+j)+3), "   ");
            strcat(*(*(letras+j)+4), "!  ");
            break;
        case ' ':
            if(strlen(*(*(letras+j))) + 7 > largura)
                j++;
                if(j==linhas)
                    break;
            if(strlen(*(*(letras+j))) == 0)
                break;
            strcat(*(*(letras+j)+0), "       ");
            strcat(*(*(letras+j)+1), "       ");
            strcat(*(*(letras+j)+2), "       ");
            strcat(*(*(letras+j)+3), "       ");
            strcat(*(*(letras+j)+4), "       ");
            break;
        default:
            break;
        }
    }
}



int tamanho(char *palavra) {
    int tamanhos[] = {7, 7, 7, 7, 7, 7, 7, 7, 3, 7, 6, 7, 9, 7, 7, 7, 8, 7, 7, 9, 7, 1,1 ,9 ,7 ,7 ,7 ,7 };
    int tamanhosnumero[] = {8, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int contador = 0;
    int i;
    for(i=0;*(palavra+i)!=' '&&*(palavra+i)!='\0';i++) {
        if(*(palavra+i) >= 'a' && *(palavra+i) <= 'z')
            contador += tamanhos[*(palavra+i)-97];
        else if((*(palavra+i) >= '0' && *(palavra+i) <= '9'))
            contador += tamanhos[*(palavra+i)-30];
        else if(*(palavra+i) == ',')
            contador += 5;
        else if(*(palavra+i) == '!')
            contador += 2;

    }
    return contador;
}

int main()
{
    char ***letras = NULL;
    char *palavra = (char*)malloc(150*sizeof(char));
    int linhas = 3;
    int altura = 5;
    int largura = 100;

    printf("Frase: ");
    gets(palavra);
    printf("\n\n\n");
    aloca(&letras, linhas, altura, largura);
    atribui(letras, palavra, linhas, altura, largura);
    mostra_frase(letras, linhas, altura, largura);
    printf("\n\n\n");
}


