#ifndef PILHA_H
#define PILHA_H

typedef struct pilha_t pilha_t;

pilha_t* pilha_criar();
int pilha_empilhar(pilha_t *p, int elemento);
int pilha_desempilhar(pilha_t *p, int *elemento);
int pilha_topo(pilha_t *p, int *elemento);
int pilha_esta_vazia(pilha_t *p);
void pilha_exibir(pilha_t *p);
void pilha_destruir(pilha_t *p);

#endif