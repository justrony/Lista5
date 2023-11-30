#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void binarizarMatriz(int **matrizM, int **matrizS, int linhas, int colunas, int limiar) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizS[i][j] = (matrizM[i][j] > limiar) ? 1 : 0;
        }
    }
}

int main() {
    srand(time(NULL));

    int linhas, colunas, limiar;
    
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    if (linhas <= 0 || colunas <= 0) {
        printf("As dimensoes da matriz devem ser numeros positivos.\n");
        return 1;
    }

    printf("Digite o limiar: ");
    scanf("%d", &limiar);

    int **matrizM = (int **)malloc(linhas * sizeof(int *));
    int **matrizS = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matrizM[i] = (int *)malloc(colunas * sizeof(int));
        matrizS[i] = (int *)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizM[i][j] = rand() % 100;
        }
    }

    printf("Matriz M (Original):\n");
    imprimirMatriz(matrizM, linhas, colunas);

    binarizarMatriz(matrizM, matrizS, linhas, colunas, limiar);

    printf("\nMatriz S (Binarizada com limiar %d):\n", limiar);
    imprimirMatriz(matrizS, linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        free(matrizM[i]);
        free(matrizS[i]);
    }
    free(matrizM);
    free(matrizS);

    return 0;
}
