#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


float calcularMSE(int *vetorA, int *vetorB, int tamanho) {
    float somaQuadrados = 0.0;

    for (int i = 0; i < tamanho; i++) {
        somaQuadrados += pow(vetorA[i] - vetorB[i], 2);
    }

    return somaQuadrados / tamanho;
}

int main() {
    srand(time(NULL));

    int tamanho;

    printf("Digite a dimensao dos vetores: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("A dimensao dos vetores deve ser um número positivo.\n");
        return 1;
    }

    int *vetorA = (int *)malloc(tamanho * sizeof(int));
    int *vetorB = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        vetorA[i] = rand() % 100;
        vetorB[i] = rand() % 100;
    }

    printf("Vetor A: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetorA[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Vetor B: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetorB[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    float mse = calcularMSE(vetorA, vetorB, tamanho);
    printf("Erro Medio Quadratico: %.2f\n", mse);

    free(vetorA);
    free(vetorB);

    return 0;
}
