#include <stdio.h>

long long fatorial_iterativo(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Numero invalido.\n");
    } else {
        printf("Iterativo: %lld (Complexidade O(n))\n", fatorial_iterativo(n));
        printf("Recursivo: %lld (Complexidade O(n))\n", fatorial_recursivo(n));
    }
    return 0;
}
