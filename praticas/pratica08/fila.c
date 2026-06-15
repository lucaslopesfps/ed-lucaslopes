#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

fila_t* fila_criar() {
    fila_t *f = (fila_t*) malloc(sizeof(fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(fila_t *f) {
    return (f == NULL || f->inicio == NULL);
}

int fila_enfileirar(fila_t *f, int elemento) {
    if (f == NULL) return 0;
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = elemento;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo; 
    } else {
        f->fim->proximo = novo; 
    }
    f->fim = novo; 
    return 1;
}


int fila_desenfileirar(fila_t *f, int *elemento) {
    if (fila_esta_vazia(f)) return 0;

    no_t *aux = f->inicio;
    *elemento = aux->valor; 
    f->inicio = aux->proximo; 

    if (f->inicio == NULL) {
        f->fim = NULL; 
    }

    free(aux); 
    return 1;
}

int fila_inicio(fila_t *f, int *elemento) {
    if (fila_esta_vazia(f)) return 0;
    *elemento = f->inicio->valor;
    return 1;
}

void fila_exibir(fila_t *f) {
    if (fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    no_t *atual = f->inicio;
    printf("Conteudo da Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void fila_destruir(fila_t *f) {
    if (f == NULL) return;
    no_t *atual = f->inicio;
    while (atual != NULL) {
        no_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(f);
}