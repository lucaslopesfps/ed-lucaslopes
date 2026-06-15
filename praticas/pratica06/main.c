#include <stdio.h>
#include "lista_linear.h"

int main() {
    lista_t *minha_lista = lista_criar();

    printf("--- Testando a Lista Linear Dinamica (Pratica 06) ---\n\n");

    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_exibir(minha_lista);

    int buscar = 20;
    if (lista_buscar(minha_lista, buscar)) {
        printf("Elemento %d encontrado na lista.\n", buscar);
    } else {
        printf("Elemento %d nao encontrado.\n", buscar);
    }

    printf("\nRemovendo o elemento 20...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);

    lista_destruir(minha_lista);
    printf("\nPratica 06 concluida com sucesso!\n");

    return 0;
}