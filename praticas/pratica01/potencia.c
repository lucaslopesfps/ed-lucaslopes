#include <stdio.h>

int main() {
    int base, expoente;
    long long resultado = 1;
    printf("Digite a base e o expoente (inteiro positivo): ");
    scanf("%d %d", &base, &expoente);

    for(int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    printf("Resultado: %lld\n", resultado);
    return 0;
}