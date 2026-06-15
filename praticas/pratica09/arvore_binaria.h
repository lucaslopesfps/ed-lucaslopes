#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct arvore_t arvore_t;

arvore_t* arvore_criar();
int arvore_inserir(arvore_t *a, int elemento);
int arvore_esta_vazia(arvore_t *a);
void arvore_exibir_pre_ordem(arvore_t *a);
void arvore_exibir_em_ordem(arvore_t *a);
void arvore_exibir_pos_ordem(arvore_t *a);
void arvore_destruir(arvore_t *a);

#endif