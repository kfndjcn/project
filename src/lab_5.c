#include <stdio.h>
#include "../include/lab_5.h"

void lab_5_main(void) {
    int x[N];           // массив из N элементов
    int i, j;           // счетчики циклов
    int max_val;        // значение максимального элемента
    int max_idx = 0;    // индекс максимального элемента
    int temp;           // временная переменная для обмена

    printf("\n=== lab 5 ===\n");

    // ввод массива
    printf("enter %d integers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }

    // поиск максимального элемента и его индекса
    max_val = x[0];
    max_idx = 0;
    for (i = 1; i < N; i++) {
        if (x[i] > max_val) {
            max_val = x[i];
            max_idx = i;
        }
    }
    printf("max element: %d, its index: %d\n", max_val, max_idx);

    // зеркальное отражение элементов левее максимального
    for (i = 0, j = max_idx - 1; i < j; i++, j--) {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }

    // обнуление элементов правее максимального
    for (i = max_idx + 1; i < N; i++) {
        x[i] = 0;
    }

    // вывод массива
    printf("result: ");
    for (i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
