#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randomFloat() {
    return (float)rand() / RAND_MAX;
}
float somarElementos(float *vetor, int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
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

    float *vetor = (float *)malloc(qtdElementos * sizeof(float));

    srand(time(NULL));


    for (int i = 0; i < qtdElementos; i++) {
        vetor[i] = randomFloat() * 100.0;
    }

    printf("Vetor gerado: [");
    for (int i = 0; i < qtdElementos; i++) {
        printf("%.2f", vetor[i]);
        if (i < qtdElementos - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    float soma = somarElementos(vetor, qtdElementos);
    printf("Soma dos elementos: %.2f\n", soma);

    free(vetor);

    return 0;
}

