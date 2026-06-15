#include <stdio.h>
#include "pilha.h"

int main() {
    pilha_t *minha_pilha = pilha_criar();
    int valor_recuperado;

    printf("--- Testando a Estrutura de Pilha Dinamica (Pratica 07) ---\n\n");

    printf("Empilhando: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);

    if (pilha_topo(minha_pilha, &valor_recuperado)) {
        printf("Elemento no topo atual: %d\n", valor_recuperado);
    }

    printf("\nDesempilhando um elemento...\n");
    if (pilha_desempilhar(minha_pilha, &valor_recuperado)) {
        printf("Elemento removido: %d\n", valor_recuperado);
    }
    pilha_exibir(minha_pilha);

    pilha_destruir(minha_pilha);
    printf("\nPratica 07 concluida com sucesso!\n");

    return 0;
}