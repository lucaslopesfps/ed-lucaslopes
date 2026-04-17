#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void gerar_vetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000;
    }
}

int main() {
    int n = 100; 
    int v[100];
    clock_t t;

    srand(time(NULL));

    printf("--- Comparativo de Algoritmos de Ordenacao ---\n\n");

    gerar_vetor(v, n);
    t = clock();
    bubble_sort(v, n);
    t = clock() - t;
    printf("Tempo Bubble Sort:    %f ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    gerar_vetor(v, n);
    t = clock();
    selection_sort(v, n);
    t = clock() - t;
    printf("Tempo Selection Sort: %f ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    gerar_vetor(v, n);
    t = clock();
    quick_sort(v, 0, n - 1);
    t = clock() - t;
    printf("Tempo Quick Sort:     %f ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    printf("\nPratica concluida com sucesso!\n");

    return 0;
}