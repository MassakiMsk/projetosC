#include <stdio.h>
#include <stdlib.h>

unsigned long long int mdc(unsigned long long int a, unsigned long long int b) {
    if(b == 0)
        return a;
    return mdc(b, a % b);
}

unsigned long long int mmc(unsigned long long int a, unsigned long long int b) {
    return (a * b) / mdc(a, b);
}

int main()
{
    int n, l, i, tam;
    unsigned long long int j, mult, maior, vet[100000], multiplos[100000];
    mult = 1;

    scanf("%d %d", &n, &l);

    for(i = 0; i < n; i++) {
        scanf("%lld", &vet[i]);
        mult = mmc(mult, vet[i]);
    }

    tam = 0;
    while(l >= (tam + 2) * mult) {
        multiplos[tam] = (tam + 1) * mult;
        tam++;
    }
    maior = (tam + 1) * mult;

    printf("\n\nmmc = %lld\nMaior mmc = %lld\nmultiplos.size = %d (", mult, maior, tam);
    for(i = 0; i < tam; i++)
        printf("%lld, ", multiplos[i]);
    printf(")\n\n\n");

    for(j = 1; j <= maior; j++) {
        if(maior % j == 0)
            for(i = 0; i < tam; i++)
                if(multiplos[i] % j == 0)
                    i = tam;
            if(i == tam) {
                printf("%lld\n", j);
                return 0;
            }
    }
    return 0;
}
