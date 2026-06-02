#include <stdio.h>
#include "../include/lab_6.h"

void lab_6_main(void) {
    int x[K][N_LAB6]; // массив из K на N_LAB6 элементов
    int temp;         // временная переменная для обмена
    int i, j, m, n;

    printf("\n=== lab 6 ===\n");

    // ввод массива
    printf("enter %d elements of array:\n", K * N_LAB6);
    for (i = 0; i < K; i++) {
        for (j = 0; j < N_LAB6; j++) {
            scanf("%d", &x[i][j]);
        }
    }

    // вывод исходного массива
    printf("\noriginal array:\n");
    for (i = 0; i < K; i++) {
        for (j = 0; j < N_LAB6; j++) {
            printf("%4d ", x[i][j]);
        }
        printf("\n");
    }

    // сортировка элементов по возрастанию
    // (преобразуем двумерный массив в одномерный логически)
    for (i = 0; i < K; i++) {
        for (j = 0; j < N_LAB6; j++) {
            for (m = i; m < K; m++) {
                for (n = (m == i) ? j + 1 : 0; n < N_LAB6; n++) {
                    if (x[i][j] > x[m][n]) {
                        // обмен элементов
                        temp = x[i][j];
                        x[i][j] = x[m][n];
                        x[m][n] = temp;
                    }
                }
            }
        }
    }

    // вывод отсортированного массива
    printf("\nsorted array:\n");
    for (i = 0; i < K; i++) {
        for (j = 0; j < N_LAB6; j++) {
            printf("%4d ", x[i][j]);
        }
        printf("\n");
    }
}
