#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct hash_t {
    no_t **tabela; 
    int tamanho;   
};

int funcao_hash(int chave, int tamanho) {
    int hash = chave % tamanho;
    if (hash < 0) hash += tamanho; 
    return hash;
}

hash_t* hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    hash_t *h = (hash_t*) malloc(sizeof(hash_t));
    if (h == NULL) return NULL;

    h->tamanho = tamanho;
    h->tabela = (no_t**) malloc(tamanho * sizeof(no_t*));
    if (h->tabela == NULL) {
        free(h);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        h->tabela[i] = NULL;
    }

    return h;
}

int hash_esta_vazia(hash_t *h) {
    if (h == NULL) return 1;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) return 0;
    }
    return 1;
}

int hash_inserir(hash_t *h, int elemento) {
    if (h == NULL) return 0;

    int indice = funcao_hash(elemento, h->tamanho);

    no_t *atual = h->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == elemento) return 0; 
        atual = atual->proximo;
    }

    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = elemento;
    
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;

    return 1;
}

int hash_buscar(hash_t *h, int elemento) {
    if (h == NULL) return 0;

    int indice = funcao_hash(elemento, h->tamanho);
    no_t *atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == elemento) return 1; 
        atual = atual->proximo;
    }
    return 0; 
}

int hash_remover(hash_t *h, int elemento) {
    if (h == NULL) return 0;

    int indice = funcao_hash(elemento, h->tamanho);
    no_t *atual = h->tabela[indice];
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == elemento) {
            if (anterior == NULL) {
                h->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; 
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; 
}

void hash_exibir(hash_t *h) {
    if (h == NULL) return;

    printf("--- Estado da Tabela Hash ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("[%d]: ", i);
        no_t *atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
    printf("-----------------------------\n");
}

void hash_destruir(hash_t *h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        no_t *atual = h->tabela[i];
        while (atual != NULL) {
            no_t *aux = atual;
            atual = atual->proximo;
            free(aux);
        }
    }
    free(h->tabela);
    free(h);
}