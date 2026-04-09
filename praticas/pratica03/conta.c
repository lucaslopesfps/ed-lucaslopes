#include <stdio.h>
#include "conta.h"

void inicializar(Conta *c, int n, float s) {
    c->numero = n;
    c->saldo = s;
}

void depositar(Conta *c, float valor) {
    c->saldo += valor;
}

void sacar(Conta *c, float valor) {
    if (c->saldo >= valor) {
        c->saldo -= valor;
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void exibir(Conta c) {
    printf("Conta: %d | Saldo: R$ %.2f\n", c.numero, c.saldo);
}