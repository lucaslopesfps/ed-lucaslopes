#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    arvore_t *minha_arvore = arvore_criar();

    printf("--- Testando a Arvore Binaria de Busca (Pratica 09) ---\n\n");

    printf("Inserindo elementos: 50, 30, 70, 20, 40, 60, 80\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Percurso Pre-Ordem: ");
    arvore_exibir_pre_ordem(minha_arvore);

    printf("Percurso Em-Ordem:   ");
    arvore_exibir_em_ordem(minha_arvore);

    printf("Percurso Pos-Ordem:  ");
    arvore_exibir_pos_ordem(minha_arvore);

    arvore_destruir(minha_arvore);
    printf("\nPratica 09 executada e concluida com sucesso!\n");

    return 0;
}