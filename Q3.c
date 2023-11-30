#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *menor;
    int *maior;
} Extremos;

Extremos encontrarExtremos(int *vetor, int qtdElementos) {
    Extremos extremos;
    extremos.menor = vetor;
    extremos.maior = vetor;

    for (int i = 1; i < qtdElementos; i++) {
        if (vetor[i] < *(extremos.menor)) {
            extremos.menor = &vetor[i];
        }
        if (vetor[i] > *(extremos.maior)) {
            extremos.maior = &vetor[i];
        }
    }

    return extremos;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s <quantidade_elementos>\n", argv[0]);
        return 1;
    }

    int qtdElementos;
    sscanf(argv[1], "%d", &qtdElementos);

    if (qtdElementos <= 0) {
        printf("Deve ser um número positivo.\n");
        return 1;
    }

    int *vetor = (int *)malloc(qtdElementos * sizeof(int));

    for (int i = 0; i < qtdElementos; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor gerado: [");
    for (int i = 0; i < qtdElementos; i++) {
        printf("%d", vetor[i]);
        if (i < qtdElementos - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    Extremos extremos = encontrarExtremos(vetor, qtdElementos);

    printf("Endereco do menor elemento: %p\n", (void *)extremos.menor);
    printf("Endereco do maior elemento: %p\n", (void *)extremos.maior);

    free(vetor);

    return 0;
}
