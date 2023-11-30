#include <stdio.h>
#include <stdlib.h>

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

    // Exibe o vetor gerado
    printf("Vetor gerado: [");
    for (int i = 0; i < qtdElementos; i++) {
        printf("%d", vetor[i]);
        if (i < qtdElementos - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int *enderecoMenor = vetor;
    for (int i = 1; i < qtdElementos; i++) {
        if (vetor[i] < *enderecoMenor) {
            enderecoMenor = &vetor[i];
        }
    }

    printf("Endereco do menor elemento: %p\n", (void *)enderecoMenor);

    free(vetor);

    return 0;
}
