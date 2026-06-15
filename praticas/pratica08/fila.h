#ifndef FILA_H
#define FILA_H

typedef struct fila_t fila_t;

fila_t* fila_criar();
int fila_enfileirar(fila_t *f, int elemento);
int fila_desenfileirar(fila_t *f, int *elemento);
int fila_inicio(fila_t *f, int *elemento);
int fila_esta_vazia(fila_t *f);
void fila_exibir(fila_t *f);
void fila_destruir(fila_t *f);

#endif