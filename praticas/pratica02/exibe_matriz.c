#include <stdio.h>
#include <time.h>

int main() {
    int matriz[10][10];
    int count = 1;
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) matriz[i][j] = count++;

    clock_t start, end;

    start = clock();
    printf("Exibindo com 2 lacos:\n");
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
        }
    }
    end = clock();
    printf("Tempo O(n^2): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("\nExibindo com 1 laco:\n");
    int total_elementos = 10 * 10;
    for(int k=0; k < total_elementos; k++) {
        int i = k / 10;
        int j = k % 10; 
    }
    end = clock();
    printf("Tempo O(n^2): %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}