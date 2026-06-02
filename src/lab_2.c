#include <stdio.h>
#include "../include/lab_2.h"

int calc_lab2(float x, float eps) {
    float s = 0;
    float a;
    float c = 1;
    float b = x;
    int i = 0;

    a = c / b;

    while(1) {
        if(a <= eps) {
            break;
        }
        s = s + a;
        c = c + 1;
        b = b * x;
        a = c / b;
        i += 1;
    }

    printf("n=%d, s=%f\n", i, s);
    return i;
}

void lab_2_main(void) {
    float x, eps;

    printf("\n=== lab 2 (main) ===\n");
    printf("eps = ");
    scanf("%f", &eps);
    printf("x = ");
    scanf("%f", &x);

    float s = 0;
    float a;
    float c = 1;
    float b = x;
    int i = 0;

    a = c / b;

    while (a > eps) {
        s = s + a;
        c = c + 1;
        b = b * x;
        a = c / b;
        i = i + 1;
    }

    printf("n=%d, s=%f\n", i, s);
}

void lab_2_extra(void) {
    float x, eps;

    printf("\n=== lab 2 (additional) ===\n");
    printf("eps = ");
    scanf("%f", &eps);
    printf("x = ");
    scanf("%f", &x);

    calc_lab2(x, eps);
}
