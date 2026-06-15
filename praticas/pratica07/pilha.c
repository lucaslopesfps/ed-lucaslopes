#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct pilha_t {
    no_t *topo;
};

pilha_t* pilha_criar() {
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

int pilha_esta_vazia(pilha_t *p) {
    return (p == NULL || p->topo == NULL);
}

int pilha_empilhar(pilha_t *p, int elemento) {
    if (p == NULL) return 0;
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0; 

    novo->valor = elemento;
    novo->proximo = p->topo; 
    p->topo = novo;          
    return 1;
}

int pilha_desempilhar(pilha_t *p, int *elemento) {
    if (pilha_esta_vazia(p)) return 0;

    no_t *aux = p->topo;
    *elemento = aux->valor; 
    p->topo = aux->proximo; 
    free(aux);              
    return 1;
}

int pilha_topo(pilha_t *p, int *elemento) {
    if (pilha_esta_vazia(p)) return 0;
    *elemento = p->topo->valor;
    return 1;
}

void pilha_exibir(pilha_t *p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    no_t *atual = p->topo;
    printf("Conteudo da Pilha (Topo -> Base): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(pilha_t *p) {
    if (p == NULL) return;
    no_t *atual = p->topo;
    while (atual != NULL) {
        no_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(p);
}