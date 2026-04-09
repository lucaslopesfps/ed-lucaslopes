#ifndef CONTA_H
#define CONTA_H

typedef struct {
    int numero;
    float saldo;
} Conta;

void inicializar(Conta *c, int n, float s);
void depositar(Conta *c, float valor);
void sacar(Conta *c, float valor);
void exibir(Conta c);

#endif