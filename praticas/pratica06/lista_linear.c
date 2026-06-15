#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t *anterior;
    struct no_t *proximo;
} no_t;

struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

lista_t* lista_criar() {
    lista_t *l = (lista_t*) malloc(sizeof(lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(lista_t *l) {
    return (l == NULL || l->primeiro == NULL);
}

int lista_inserir(lista_t *l, int elemento) {
    if (l == NULL) return 0;
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = elemento;
    novo->proximo = NULL;

    if (lista_esta_vazia(l)) {
        novo->anterior = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    } else {
        novo->anterior = l->ultimo;
        l->ultimo->proximo = novo;
        l->ultimo = novo;
    }
    return 1;
}

int lista_buscar(lista_t *l, int elemento) {
    if (l == NULL) return 0;
    no_t *atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == elemento) return 1;
        atual = atual->proximo;
    }
    return 0;
}

int lista_remover(lista_t *l, int elemento) {
    if (lista_esta_vazia(l)) return 0;
    no_t *atual = l->primeiro;

    while (atual != NULL) {
        if (atual->valor == elemento) {
            if (atual == l->primeiro) {
                l->primeiro = atual->proximo;
                if (l->primeiro != NULL) l->primeiro->anterior = NULL;
                else l->ultimo = NULL;
            } else if (atual == l->ultimo) {
                l->ultimo = atual->anterior;
                l->ultimo->proximo = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void lista_exibir(lista_t *l) {
    if (lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    no_t *atual = l->primeiro;
    printf("Conteudo da Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void lista_destruir(lista_t *l) {
    if (l == NULL) return;
    no_t *atual = l->primeiro;
    while (atual != NULL) {
        no_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}