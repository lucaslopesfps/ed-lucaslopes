#include <stdio.h>

int main() {
    int vetor[100];
    int alvo, encontrado = -1;

    for(int i = 0; i < 100; i++) vetor[i] = i + 1;

    printf("Qual valor deseja buscar (1-100)? ");
    scanf("%d", &alvo);

    for(int i = 0; i < 100; i++) {
        if(vetor[i] == alvo) {
            encontrado = i;
            break; 
        }
    }

    if(encontrado != -1) printf("Valor encontrado na posicao %d\n", encontrado);
    else printf("Valor nao encontrado.\n");

    printf("\nComplexidade Assintotica:\n");
    printf("- Melhor caso: O(1) (O valor e o primeiro do vetor)\n");
    printf("- Pior caso: O(n) (O valor e o ultimo ou nao existe)\n");

    return 0;
}