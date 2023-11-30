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

int main() {
    srand(time(NULL));

    int n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O tamanho dos vetores deve ser um número positivo.\n");
        return 1;
    }

    int *vetorX = (int *)malloc(n * sizeof(int));
    int *vetorY = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        vetorX[i] = rand() % n; 
        vetorY[i] = rand() % n; 
    }

    printf("Vetor X: [");
    for (int i = 0; i < n; i++) {
        printf("%d", vetorX[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Vetor Y: [");
    for (int i = 0; i < n; i++) {
        printf("%d", vetorY[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int **matrizM = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrizM[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        matrizM[vetorX[i]][vetorY[i]]++;
    }

    printf("\nMatriz M:\n");
    imprimirMatriz(matrizM, n);

    free(vetorX);
    free(vetorY);

    for (int i = 0; i < n; i++) {
        free(matrizM[i]);
    }
    free(matrizM);

    return 0;
}
