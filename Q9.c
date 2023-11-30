#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(int **matriz, int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int ehPar(int numero) {
    return numero % 2 == 0;
}

void verificarSomaDiagonal(int **matriz, int ordem) {
    int somaDiagonal = 0;
    for (int i = 0; i < ordem; i++) {
        somaDiagonal += matriz[i][i];
    }

    printf("Soma da diagonal principal: %d\n", somaDiagonal);
    if (ehPar(somaDiagonal)) {
        printf("A soma da diagonal principal e par.\n");
    } else {
        printf("A soma da diagonal principal e impar.\n");
    }
}

int main() {
    srand(time(NULL));

    int ordem;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    if (ordem <= 0) {
        printf("A ordem da matriz deve ser um numero positivo.\n");
        return 1;
    }

    int **matriz = (int **)malloc(ordem * sizeof(int *));
    for (int i = 0; i < ordem; i++) {
        matriz[i] = (int *)malloc(ordem * sizeof(int));
    }

    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            matriz[i][j] = rand() % 100;
        }
    }

    printf("Matriz Gerada:\n");
    imprimirMatriz(matriz, ordem);

    verificarSomaDiagonal(matriz, ordem);


    for (int i = 0; i < ordem; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
