#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Uso: %s <valor1> <valor2> <operacao>\n", argv[0]);
        return 1;
    }
    int valor1, valor2;
    sscanf(argv[1], "%d", &valor1);
    sscanf(argv[2], "%d", &valor2);

    char operacao = argv[3][0];

    switch (operacao) {
        case 's':
            printf("Soma: %d\n", valor1 + valor2);
            break;
        case 'm':
            printf("Multiplicacao: %d\n", valor1 * valor2);
            break;
        default:
            printf("Use 's' para soma ou 'm' para multiplicação.\n");
            return 1;
    }

    return 0;
}
