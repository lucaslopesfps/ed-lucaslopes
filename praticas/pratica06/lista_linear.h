#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

typedef struct lista_t lista_t;

lista_t* lista_criar();
int lista_inserir(lista_t *l, int elemento);
int lista_remover(lista_t *l, int elemento);
int lista_buscar(lista_t *l, int elemento);
void lista_exibir(lista_t *l);
int lista_esta_vazia(lista_t *l);
void lista_destruir(lista_t *l);

#endif