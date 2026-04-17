#include <stdio.h>

long long calcular_potencia(int base, int expoente) {
    long long res = 1;
    for(int i = 0; i < expoente; i++) {
        res *= base;
    }
    return res;
}

int main() {
    int base, expoente;
    printf("Digite a base e o expoente (inteiro positivo): ");
    scanf("%d %d", &base, &expoente);

    printf("Resultado: %lld\n", calcular_potencia(base, expoente));
    return 0;
}