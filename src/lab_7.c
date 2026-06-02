#include <stdio.h>
#include "../include/lab_7.h"

void lab_7_main(void) {
    unsigned long z;
    unsigned long mask;

    printf("\n=== lab 7 ===\n");
    printf("z = ");
    scanf("%lx", &z);

    if (z != 0) {
        // Находим младшую единицу: z & -z даёт число с единственной единицей
        // на месте младшей единицы z
        unsigned long lowest_bit = z & -z;

        // Маска для обнуления всех битов левее младшей единицы:
        // lowest_bit - 1 даёт все единицы правее младшей единицы,
        // lowest_bit | (lowest_bit - 1) — сама младшая единица и всё правее
        mask = lowest_bit | (lowest_bit - 1);

        z = z & mask;
    }

    printf("result: %lx\n", z);
}
