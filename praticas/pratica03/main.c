#include <stdio.h>
#include "conta.h"

int main() {
    Conta minhaConta;
    
    inicializar(&minhaConta, 123, 500.0);
    exibir(minhaConta);
    
    depositar(&minhaConta, 200.0);
    sacar(&minhaConta, 100.0);
    
    printf("Apos movimentacoes:\n");
    exibir(minhaConta);
    
    return 0;
}