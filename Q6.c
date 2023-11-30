#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcularMedia(int *vetor, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}
float calcularMediana(int *vetor, int tamanho) {

    qsort(vetor, tamanho, sizeof(int), comparar);

    if (tamanho % 2 != 0) {
        return vetor[tamanho / 2];
    }

    int meio1 = vetor[tamanho / 2 - 1];
    int meio2 = vetor[tamanho / 2];
    return (float)(meio1 + meio2) / 2;
}
int calcularModa(int *vetor, int tamanho) {

    qsort(vetor, tamanho, sizeof(int), comparar);

    int moda = vetor[0];
    int contagemAtual = 1;
    int modaAtual = 1;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] == vetor[i - 1]) {
            contagemAtual++;
        } else {
            contagemAtual = 1;
        }

        if (contagemAtual > modaAtual) {
            modaAtual = contagemAtual;
            moda = vetor[i];
        }
    }

    return moda;
}

int main() {
    srand(time(NULL));

    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho do vetor deve ser um número positivo.\n");
        return 1;
    }
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
    printf("Vetor gerado: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    float media = calcularMedia(vetor, tamanho);
    printf("Media: %.2f\n", media);

    float mediana = calcularMediana(vetor, tamanho);
    printf("Mediana: %.2f\n", mediana);

    int moda = calcularModa(vetor, tamanho);
    printf("Moda: %d\n", moda);

    free(vetor);

    return 0;
}
