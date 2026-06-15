#include <stdio.h>
#include "fila.h"

int main() {
    fila_t *minha_fila = fila_criar();
    int item_removido;

    printf("--- Testando a Estrutura de Fila Dinamica (Pratica 08) ---\n\n");

    printf("Enfileirando: 10, 20, 30\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_exibir(minha_fila);

    if (fila_inicio(minha_fila, &item_removido)) {
        printf("Proximo a ser atendido (Inicio): %d\n", item_removido);
    }

    printf("\nDesenfileirando o primeiro elemento...\n");
    if (fila_desenfileirar(minha_fila, &item_removido)) {
        printf("Elemento removido com sucesso: %d\n", item_removido);
    }
    fila_exibir(minha_fila);

    fila_destruir(minha_fila);
    printf("\nPratica 08 concluida sem erros!\n");

    return 0;
}