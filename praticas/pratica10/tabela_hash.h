#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct hash_t hash_t;

hash_t* hash_criar(int tamanho);
int hash_inserir(hash_t *h, int elemento);
int hash_buscar(hash_t *h, int elemento);
int hash_remover(hash_t *h, int elemento);
void hash_exibir(hash_t *h);
int hash_esta_vazia(hash_t *h);
void hash_destruir(hash_t *h);

#endif