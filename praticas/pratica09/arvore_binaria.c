#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} no_t;

struct arvore_t {
    no_t *raiz;
};

arvore_t* arvore_criar() {
    arvore_t *a = (arvore_t*) malloc(sizeof(arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(arvore_t *a) {
    return (a == NULL || a->raiz == NULL);
}

no_t* inserir_recursivo(no_t *raiz, int elemento, int *sucesso) {
    if (raiz == NULL) {
        no_t *novo = (no_t*) malloc(sizeof(no_t));
        if (novo == NULL) {
            *sucesso = 0;
            return NULL;
        }
        novo->valor = elemento;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *sucesso = 1;
        return novo;
    }

    if (elemento < raiz->valor) {
        raiz->esquerda = inserir_recursivo(raiz->esquerda, elemento, sucesso);
    } else if (elemento > raiz->valor) {
        raiz->direita = inserir_recursivo(raiz->direita, elemento, sucesso);
    } else {
        
        *sucesso = 0;
    }
    return raiz;
}

int arvore_inserir(arvore_t *a, int elemento) {
    if (a == NULL) return 0;
    int sucesso = 0;
    a->raiz = inserir_recursivo(a->raiz, elemento, &sucesso);
    return sucesso;
}

void pre_ordem(no_t *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(no_t *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(no_t *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void arvore_exibir_pre_ordem(arvore_t *a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        pre_ordem(a->raiz);
    }
    printf("\n");
}

void arvore_exibir_em_ordem(arvore_t *a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        em_ordem(a->raiz);
    }
    printf("\n");
}

void arvore_exibir_pos_ordem(arvore_t *a) {
    if (arvore_esta_vazia(a)) {
        printf("Arvore vazia.");
    } else {
        pos_ordem(a->raiz);
    }
    printf("\n");
}

void destruir_recursivo(no_t *raiz) {
    if (raiz != NULL) {
        destruir_recursivo(raiz->esquerda);
        destruir_recursivo(raiz->direita);
        free(raiz);
    }
}

void arvore_destruir(arvore_t *a) {
    if (a == NULL) return;
    destruir_recursivo(a->raiz);
    free(a);
}