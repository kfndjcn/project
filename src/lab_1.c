#include <stdio.h>
#include "lab_1.h"

// Вспомогательная функция для дополнительного задания
float calc(float A, float B, float C) {
    return ((A/B + C*C) / (A*C));
}

// Основное задание
void lab_1_main(void) {
    float A, B, C, P;

    printf("\n=== lab 1 (main) ===\n");
    printf("A = ");
    scanf("%f", &A);
    printf("B = ");
    scanf("%f", &B);
    printf("C = ");
    scanf("%f", &C);

    P = ((A/B) + C*C) / (A*C);

    printf("P = %f\n", P);
}

// Дополнительное задание
void lab_1_extra(void) {
    float A, B, C, P;

    printf("\n=== lab 1 (additional) ===\n");
    printf("A = ");
    scanf("%f", &A);
    printf("B = ");
    scanf("%f", &B);
    printf("C = ");
    scanf("%f", &C);

    P = calc(A, B, C);
    printf("P = %f\n", P);
}
