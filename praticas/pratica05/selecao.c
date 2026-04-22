#include "selecao.h"

int linear_search(int vetor[], int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == elemento) return i;
    }
    return -1;
}

int quick_select(int vetor[], int esq, int dir, int k) {
    if (esq <= dir) {
        int pivo = vetor[dir];
        int i = esq;
        for (int j = esq; j < dir; j++) {
            if (vetor[j] <= pivo) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                i++;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[dir];
        vetor[dir] = temp;

        if (i == k) return vetor[i];
        if (i > k) return quick_select(vetor, esq, i - 1, k);
        return quick_select(vetor, i + 1, dir, k);
    }
    return -1;
}