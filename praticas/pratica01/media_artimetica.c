#include <stdio.h>


float calcular_media(float soma, int n) {
    return soma / n;
}

int main() {
    int n;
    float numero, soma = 0;

    printf("Quantos numeros (max 100)? ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Valor invalido!\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &numero);
        soma += numero;
    }

    printf("Media: %.2f\n", calcular_media(soma, n)); 
    return 0;
}
