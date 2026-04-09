#include <stdio.h>

int main() {
    int saque, notas[] = {200, 100, 50, 20, 10, 5, 2};
    printf("Valor do saque (max 1000): ");
    scanf("%d", &saque);

    if (saque > 1000 || saque < 2) {
        printf("Valor indisponivel.\n");
        return 1;
    }

    printf("Notas entregues:\n");
    for(int i = 0; i < 7; i++) {
        int qtd = saque / notas[i];
        if (qtd > 0) {
            printf("%d nota(s) de R$ %d\n", qtd, notas[i]);
            saque %= notas[i];
        }
    }
    return 0;
}