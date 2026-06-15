#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_t *minha_tabela = hash_criar(7);

    printf("--- Testando a Tabela Hash com Encadeamento (Pratica 10) ---\n\n");

    printf("Inserindo elementos: 12, 15, 8, 20, 27, 34\n");
    hash_inserir(minha_tabela, 12);
    hash_inserir(minha_tabela, 15);
    hash_inserir(minha_tabela, 8); 
    hash_inserir(minha_tabela, 20);
    hash_inserir(minha_tabela, 27);
    hash_inserir(minha_tabela, 34);
    
    hash_exibir(minha_tabela);

    int elemento_busca = 8;
    printf("\nBuscando pelo elemento %d...\n", elemento_busca);
    if (hash_buscar(minha_tabela, elemento_busca)) {
        printf("Elemento %d encontrado na tabela!\n", elemento_busca);
    } else {
        printf("Elemento %d nao encontrado.\n", elemento_busca);
    }

    printf("\nRemovendo o elemento 15...\n");
    hash_remover(minha_tabela, 15);
    hash_exibir(minha_tabela);

    hash_destruir(minha_tabela);
    printf("\nPratica 10 finalizada e liberada sem vazamentos de memoria!\n");

    return 0;
}