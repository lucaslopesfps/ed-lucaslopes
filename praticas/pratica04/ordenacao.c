#include "ordenacao.h"

void bubble_sort(int vetor[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selection_sort(int vetor[], int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }
}

void quick_sort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = vetor[alto];
        int i = (baixo - 1);
        int aux;

        for (int j = baixo; j <= alto - 1; j++) {
            if (vetor[j] < pivo) {
                i++;
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        aux = vetor[i + 1];
        vetor[i + 1] = vetor[alto];
        vetor[alto] = aux;
        
        int particao = i + 1;

        quick_sort(vetor, baixo, particao - 1);
        quick_sort(vetor, particao + 1, alto);
    }
}