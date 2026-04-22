#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

int main() {
    int n = 100;
    int v[100];
    srand(time(NULL));

    for (int i = 0; i < n; i++) v[i] = rand() % 1000;

    int alvo = v[rand() % n];
    
    printf("Buscando o elemento: %d\n", alvo);
    int pos = linear_search(v, n, alvo);
    printf("Encontrado na posicao (Linear): %d\n", pos);

    // Exemplo: encontrar o 5º menor elemento usando Quick Select
    int k = 5;
    int valor_k = quick_select(v, 0, n - 1, k);
    printf("O %do menor elemento e: %d\n", k + 1, valor_k);

    printf("\nPratica 05 concluida!\n");
    return 0;
}